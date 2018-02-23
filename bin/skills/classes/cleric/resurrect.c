/** Raise Dead **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status resurrect(string targ, mixed alt_type, string class) {
  object dead;
  int i;
  string file;

  if(!targ) {
    notify_fail("resurrect who?\n");
    return 0;
  }
  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  if((dead = find_player(targ))) {
    if(!dead->query_dead()) {
      write(capitalize(targ) +" is not dead!\n");
      return 1;
    }
  }
  else {
    write("The essence of "+ capitalize(targ) +" does not exist.\n");
    return 1;
  }

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Resurrect",
  "sphere",            alt_type, 
  "cost",              35,
  "level",             35,
  "class", class,
  "cast time",         3,
  "casting msg", ({
    "You call upon the gods to give life to "+ capitalize(targ) +".\n",
    "You feel the essence of "+ capitalize(targ) +" coalescing.\n",
  }),
  "casting room", ({
    NAME +" calls upon the gods to give life to "+ capitalize(targ) +".\n",
    "You feel the essence of "+ capitalize(targ) +" coalescing.\n",
  }),
  "spell object",     file,
  "passive",
  "argument",         targ,
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int dmg) {
  string *stats;
  int i;


  if((target = find_player((string)caster->query_spell_argument()))) {
    if(!target->query_dead()) {
      write(target->query_name() +" is not dead!\n");
    }
    else {
      write("You resurrect "+ target->query_name() +" from the dead.\n");
      target->toggle_ghost();
      move_object(target, environment(caster));
      caster->add_exp((int)target->query_level() * 150);

      stats = ({ 
                 "constitution", "intelligence", "wisdom", "charisma",
                 "strength",     "dexterity",    "combat",
              });
      for(i = 0; i < 4; i++) {
        call_other(target,"adj_"+ stats[random(sizeof(stats))],1);
      }
      target->heal_self(1000);
    }
  }
  else {
    write("The essence of "+ target->query_name() +" has left the world.\n");
  }    
  destruct(this_object());
  return 1;
}

status id(string str) {
  return str == "spell"
      || str == "raise";
}

