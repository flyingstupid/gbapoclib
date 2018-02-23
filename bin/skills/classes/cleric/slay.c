/* Slay Living. Drakken, January 1994 */
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status slay(string targ, mixed alt_type, string class) {
  int dam, i;
  string file;
 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  if(!targ || !(targ == "living" || sscanf(targ,"living %s", targ))) {
    notify_fail("slay living?\n");
    return 0;
  }
  if((status)environment(this_player())->query_no_fight() == 1){
     write("You are not allowed to cast spells here.\n");
     return 1;
}
  if(targ == "living") targ = (string)this_player()->query_attacker();
  if(!targ) {
    notify_fail("slay living <who>?\n");
    return 0;
  }
  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(6) + 1);
  if(dam > 60) dam = 60;   
 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Slay Living",
  "sphere",            alt_type, 
  "cost",              35,
  "damage",            dam,
  "immune",            "death",
  "level",             30,
  "class", class,
  "cast time",         4,
  "casting msg", ({ 
     "You call upon the gods of evil to bring death to your opponent.\n",
     "You stare deeply into the eyes of "+ targ +".\n",
  }),
  "casting msg room",  ({  
      NAME+" calls upon the gods, to bring death to "+capitalize(targ)+".\n",
      NAME+" stares deeply into the eyes of "+capitalize(targ)+".\n",
  }),
  "spell object",      file,
  }));
  return 1;
}
 
 
/****************************************************************/
/* when cloned to target */
 
status cast_spell(object caster,object target,object prev,int dmg) {
#ifndef PLAYERKILL
   if(!(caster->query_npc() || target->query_npc())){
         tell_room(environment(target),"Nothing happens...\n");
    destruct(this_object());
     return 1;
}
#endif
  if(target == caster) {
    destruct(this_object());
    return 1;
  }
   if(target->query_level() <= 18){
    if(target != caster) {
      tell_object(caster,(string)target->query_name()+
                  " falls to the ground, dead...\n");
    }
    tell_object(target, "You fall to the ground, dead...!\n");
    say((string)target->query_name()+
        " falls to the ground, dead!\n", target);
    target->death();
    destruct(this_object());
    return 1;  /* do not do damage */
  }
  destruct(this_object());
  return 0;  /* do damage */
}

