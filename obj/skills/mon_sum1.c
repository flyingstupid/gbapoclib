/* monster summon 1 */

inherit "/obj/skills/summoned";

void reset(status arg) {
    ::reset(arg);
    if (arg) return;
    set_msgin("follows its master");
    set_msgout("goes after its master");
    set_alias("summoned");
    set_enchanted(1);
}

status cast_spell(object caster,object target,object prev,int level) {
  int type, number;
  object summoned;
  int i;

  if(environment(caster)->query_no_summon()) {
    write("Something prevents you summoning.\n");
    destruct(this_object());
    return 1;
  }

  type = random(3);
  switch(type) {
    case 0:
      set_name("caracara");
      set_level(9);
      set_race("caracara");
      set_short("Caracara");
      set_long("A bird of prey 20 inches tall with dark brown feathers, "+
               "a white throat, a\nblack cap, white wing tips and a "+
               "black band at the base of the tail.\n");
    break;

    case 1:
      set_name("hornet");
      set_level(5);
      set_race("hornet");
      set_short("Hornet");
      set_long("A hornet, a large wasp.\n");
    break;

    case 2:
      set_name("rat");
      set_level(5);
      set_race("rat");
      set_short("Rat");
      set_long("This is a disease ridden black rat.\n");
    break;
  }
  for(i = 1; summoned = present("summoned "+ i, environment(caster)); i++) {
    if((object)summoned->query_master() == caster) {
      write("You cannot control another summoned creature.\n");
      destruct(this_object());
      return 1;
    } 
  }
  clone_object("obj/shadows/follow")->follow(caster,this_object());
  return ::cast_spell(caster,target,prev,level);
}

