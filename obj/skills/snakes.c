/* sticks to snakes */

inherit "/obj/skills/summoned";

void reset(status arg) {
    ::reset(arg);
    if (arg) return;
    set_msgin("follows its master");
    set_msgout("goes after its master");
    set_alias("animated");
    set_enchanted(1);
}

status cast_spell(object caster,object target,object prev,int level) {
  int type, number;
  object summoned;
  int i;

  if(environment(caster)->query_no_summon()) {
    write("Something prevents you animating the stick.\n");
    destruct(this_object());
    return 1;
  }

  type = random(3);
  switch(type) {
    case 0:
      set_name("black snake");
      set_race("snake");
      set_level(5);
      set_alias("snake");
      set_short("Black Snake");
      set_long("A two foot black snake created from a stick.\n");
    break;

    case 1:
      set_name("rat snake");
      set_race("snake");
      set_level(2);
      set_alias("snake");
      set_short("Rat Snake");
      set_long("A two foot red rat snake created from a stick.\n");
    break;

    case 2:
      set_name("constrictor");
      set_race("snake");
      set_level(1);
      set_alias("snake");
      set_short("Constrictor");
      set_long("A three foot boa constrictor created from a stick.\n");
    break;
  }
  for(i = 1; summoned = present("animated "+ i, environment(caster)); i++) {
    if((object)summoned->query_master() == caster) {
      write("You cannot control another animated creature.\n");
      destruct(this_object());
      return 1;
    } 
  }
  return ::cast_spell(caster,target,prev,level);
}


void heart_beat() {
  object at;

  if((at = query_primary_attack()) && environment(at) == environment()) {
    if(random(100) < 5 && !present("Poison", at)) {
      object poison;

      poison = clone_object("objects/poison");
      move_object(poison, at);
    }
  }
  ::heart_beat();
}

