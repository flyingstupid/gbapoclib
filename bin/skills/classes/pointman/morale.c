/* Morale 
 * This is identical to the priest spell prayer, but is level 5
 * as it is an area effect. Note also, that this effect can be
 * cumulative to bless/prayer spells.
 * (c) Angel, June 1998
 */

inherit "obj/skills/sp_weap";
inherit "obj/skills/sp_arm";

status morale(string targ, mixed alt_type) {
  string file;
  int i, cl;

  if(!alt_type) alt_type = "fighting";
  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
    "target",            targ,
    "name",              "morale boosting",
    "sphere",            alt_type, 
    "cost",              0,
    "level",             8,
    "cast time",         1,
    "spell object",      file,
    "damage",            cl,  /* as time */
    "class",             "pointman",
    "passive",
  }));
  return 1;
}

/*********************************************************************/
/* when cloned to player */

status cast_spell(object caster,object target,object prev,int dmg) {
  object banner, ob, bless;
  object *obj;
  object *people;
  string *members;
  int max_combat;
  int i;

  if(!banner = present("party_object", caster)) {
    write("You are not in a party!\n");
    destruct(this_object());
    return 1;
  }

  members = (string *)banner->query_all_members();
  people  = ({ });

  for(i=0; i<sizeof(members); i++) {
    if((ob=present(members[i], environment(caster))) && find_player(members[i]))
      people += ({ ob, });
  }

  if(sizeof(people) == 1) {
    write("A party of one isn't big enough for your song!\n");
    destruct(this_object());
    return 1;
  }

  write("You sing a mighty song of glory, boosting the morale of '"+
	caster->query_party()+"' !!\n");

  for(i=0; i<sizeof(people); i++) 
  {
    if(bless = present("morale boost", people[i]))
    {
        bless->time_out();
    }
    bless = present("morale boost",people[i]);    
    if(bless) 
    {      
        if(target != caster) 
        {
            tell_object(caster,"You extend the time of your morale boosting upon "+
            (string)target->query_name()+".\n");      
        }
        else
        {
            write("You extend the time of your morale boosting song.\n");
        } 
    
        bless->adj_time(dmg*60);
        destruct(this_object());
        return 1;    
    }    
        write(people[i]->query_name() +" feels "+people[i]->query_possessive() +
	"spirits soar!\n");

    tell_object(people[i], "As "+caster->query_name() +" sings a song of glory and hope, you feel your spirits soar!\n");

    bless = clone_object("bin/skills/classes/bard/morale");
    move_object(bless, people[i]);
    bless -> set_name("morale boost");
    bless -> set_wc_bonus(2);
    bless -> set_ac_bonus(2);
    bless -> adj_time(dmg * 60);
    people[i] -> recalc_ac();
    people[i] -> recalc_wc();
    return 1; /* don't do damage */
  }
}

