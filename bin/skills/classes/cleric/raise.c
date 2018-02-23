/** Raise Dead **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status raise(string targ, mixed alt_type, string class) {
  object dead, *inv;
  int i, here;
  string file;

  here = 0;
  if(!targ || sscanf(targ,"dead %s",targ) != 1) {
    notify_fail("raise dead?\n");
    return 0;
  }
  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  if((dead = present(targ, environment(this_player())))) {
    if(living(dead) || (dead = find_player(targ))) {
      if(!dead->query_dead()) {
        write(capitalize(targ) +" is not dead!\n");
        return 1;
      }
    }
  }
  else {
    inv = all_inventory(environment(this_player()));
    for(i = 0 ; i < sizeof(inv) ; i++)
      if(inv[i]->query_corpse_name() == capitalize(targ)) {
        here = 1;
        if(find_living(targ)->query_ghost()) {
          move_object(find_living(targ), environment(this_player()));
        } else {
          write(capitalize(targ) +" is not dead!\n");
          return 1;
        }
      }
    if(!here) {
      write("The essence of "+ capitalize(targ) +" is not here.\n");
      return 1;
    }
  }

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Raise Dead",
  "sphere",            alt_type, 
  "cost",              18,
  "level",             18,
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
  "spell object",  file,
  "passive",
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int dmg) {
  string *stats;
  int i;

  if(living(target) || (target = find_player((string)target->query_name()))) {
    if(!target->query_dead()) {
      write(target->query_name() +" is not dead!\n");
    }
    else {
      write("You raise "+ target->query_name() +" from the dead.\n");
      target->toggle_ghost();
      move_object(target, environment(caster));
      caster->add_exp((int)target->query_level() * 100);

      stats = ({ 
                 "constitution", "intelligence", "wisdom", "charisma",
                 "strength",     "dexterity",    "combat",
              });
      for(i = 0; i < 3; i++) {
        call_other(target,"adj_"+ stats[random(sizeof(stats))],1);
      }
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

