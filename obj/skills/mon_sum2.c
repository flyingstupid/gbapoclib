/* monster summon 2 */

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
    write("Something prevents the summoning.\n");
    destruct(this_object());
    return 1;
  }


  type = random(3);
  switch(type) {
    case 0:
      set_name("bear");
      set_level(10);
      set_race("bear");
      set_short("Bear");
      set_long("The bear growls as you stare at it.\n"+
               "It looks like a Grizzly Bear.\n");
    break;

    case 1:
      set_name("wolf");
      set_level(7);
      set_race("wolf");
      set_short("Wolf");
      set_long("Your mind sinks into the void of the black wolf's eyes.\n");
     break;

     case 2:
       set_name("leopard");
       set_level(11);
       set_race("leopard");
       set_short("Leopard");
       set_long("The leopard's sleek body is taut, "+
                "ready to leap upon prey.\n");
     break;
  }
  for(i = 1; summoned = present("summoned "+ i, environment(caster)); i++) {
    if((object)summoned->query_master() == caster) {
      write("You cannot control another summoned creature.\n");
      destruct(this_object());
      return 1;
    } 
  }
  clone_object("obj/shadows/follow")->follow(caster, this_object());
  return ::cast_spell(caster,target,prev,level);
}

