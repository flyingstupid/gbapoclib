/** Resuscitation **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status resuscitate(string targ, mixed alt_type, string class) {
  object dead;
  int i;
  string file;

  if(!targ) {
    notify_fail("resuscitate who?\n");
    return 0;
  }
  if(!alt_type) alt_type = "mhealing";
  if(!class) class = "medic";
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
  "name",              "Resuscitate",
  "sphere",            alt_type, 
  "cost",              0,
  "level",             3,
  "class",            class,
  "cast time",         10,
  "casting msg", ({
    "You quickly begins to setup the defibulator to bring "+ capitalize(targ) +" back to conciousness.\n",
    "You adjust the dials and calibrate the machine..\n",
    "You yell, \"CLEAR\", ensuring everyone is back and then activate the machine!\n",
    capitalize(targ) +"'s body jumps and then begins hacking and coughing!\n",
  }),
  "casting room", ({
    NAME +" quickly setups a defibulator, attatching electrodes to "+ capitalize(targ) +" body!\n",
    NAME + " adjusts some dials and presses some buttons on the machine",
    NAME + " yells, \"CLEAR\" and pushes everyone back, activating the machine!\n",
    capitalize(targ)+"'s body jump and then begins hacking and cought!\n",
  }),
  "spell object",     file,
  "passive",
  "component", "defibulator",
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
      write("You've resuscitated "+ target->query_name() +"!\n");
      target->toggle_ghost();
      move_object(target, environment(caster));
      write("You learn something important from this experience\n");
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