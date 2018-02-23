/* finger of death */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define POSSESSIVE "@@query_possessive:$this_player()$@@"

status fod(mixed targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!alt_type) alt_type = "charm";
  if(!class) class = "mage";

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Finger of Death",
  "sphere",            alt_type, 
  "cost",              20,
  "damage",            2, /* save flag */
  "immune",            "death",
  "level",             20, /* instant kill spell */
  "class", class,
  "cast time",         2,
  "casting msg",      "You feel a surge of power as you point your finger.\n",
  "casting msg room", NAME +" starts to point "+ POSSESSIVE +" finger.\n",
  "spell object",     file,

/* other spell options...
  "area",
  "passive",
  "component",         0,
 */
  }));
  return 1;
}


/****************************************************************/
/* when cloned to target */

status cast_spell(object caster,object target,object prev,int dmg) {
#ifndef PLAYERKILL
  if(!(caster->query_npc() || target->query_npc())) {
    tell_room(environment(target),"Nothing Happens...\n");
    destruct(this_object());
    return 1;
  }
#endif

  if(!(status)target->query_made_my_save()) { /* did not save */
    tell_object(target,"Your heart stops!\n");
    tell_object(caster,"You smell the scent of fear from "+
                target->query_name() +".\n");
     say("You smell the scent of fear from "+
                target->query_name() +".\n", target);
    target->death();
  }
  else {
    tell_room(environment(target),"Nothing Happens...\n");
  }
  destruct(this_object());
  return 1;
}
       

