/* Comapanion Sword

    Techman's power that brings a sword to help fight for him.

 */

/* update - dec 93 */
inherit "inherit/timer"; 

#define SWORD "obj/skills/sword"
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status csword(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "creating";
  if(!class) class = "techman";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()  /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Companion Sword",
  "sphere",            alt_type, 
  "cost",              0,
  "damage",            time,
  "level",             7, 
  "class", class,
  "casting msg",       "You see a silver sword start to appear "+
                       "in front of you.\n",
  "casting msg room",  "You see a silver sword start to appear "+
                       "in front of "+ NAME +".\n",
  "cast time",         2,
  "spell object",      file,
  "passive",
/* other spell options...
  "area",
  "immune",            0,
  "component",         0,
  "msg target",        0,
  "msg room",          0,
  "msg caster",        0,
 */
  }));
  return 1;
}

/*********************************************************************/
/* when cloned to target */

object sword;

status cast_spell(object caster,object target,object prev,int time) {
  object sp_sword;

  if(environment(caster)->query_no_summon()) {
    write("Something disrupts the nanites construction.\n");
    destruct(this_object());
    return 1;
  } 
  sp_sword = present("spellsword 2", target);
  time = (int)caster->query_spell_dmg();
  if(sp_sword) {
    sp_sword->adj_time(((time-6)*60)+60);
    write("You extend the time of the Companion Sword.\n");
    destruct(this_object());
    return 1;
  }
  tell_object(target,"Your nanites construct a perfectly silver sword.\n");
  say("A sword appears beside "+(string)target->query_name()+".\n", target);
  sword = clone_object(SWORD);
  move_object(sword,environment(target));
  adj_time(((time-6)*60)+60);
  sword->set_owner(target);
  return 1;
}

void time_out() {
  tell_object(environment(),"The sword disappears....\n");
  if(sword) destruct(sword);
  ::time_out();
}

void dispel_magic() { time_out(); }

status id(string str) {
  return str == "spell"
      || str == "spellsword";
}

status drop(status quit) {
  if(quit) time_out();
  return 1;
}

