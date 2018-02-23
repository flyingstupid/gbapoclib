
/* Death Spell. Drakken, January 1994 */
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status death(string targ, mixed alt_type, string class) {
  int dam, i;
  string file;
 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  if(!targ || !(targ == "spell" || sscanf(targ,"spell %s", targ))) {
    notify_fail("death spell?\n");
    return 0;
  }
  if(targ == "spell") targ = (string)this_player()->query_attacker();
  if(!targ) {
    notify_fail("death spell <who>?\n");
    return 0;
  }
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(6) + 1);
 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Death Spell",
  "sphere",            alt_type, 
  "cost",              30,
  "damage",            dam,
  "immune",            "death",
  "level",             35,
  "class", class,
  "cast time",         3,
  "casting msg", ({ 
     "Your body starts to glow with a red aura of power.\n",
     "The evil acrane powers of necromancy flow through your body.\n",
     "You stare deeply into the eyes of "+ targ +".\n",           
  }),
  "casting msg room",  ({  
      NAME+" starts to glow with a dark red aura of power.\n",
     "You sense strong magic within the room.\n",
      NAME+" stares deeply into the eyes of "+capitalize(targ)+".\n",
  }),
  "spell object", file,
"component", "eye#head#arm#leg#corpse#skeleton",
  }));
  return 1;
}
/****************************************************************/
/* when cloned to target */
 
status cast_spell(object caster,object target,object prev,int dmg) {
 
#ifndef PLAYERKILL
  if(!(caster->query_npc() || target->query_npc())) {
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

