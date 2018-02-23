/* monster summon 3 */

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

  type = random(2);
  switch(type) {
    case 0:
      set_name("fire giant");
      set_race("giant");
      set_level(19);
      set_magic_resist(20);
      set_gender(1);
      add_spell_immune("fire");
      set_al(-200);
      load_chat(5, ({ "Giant says:  Dreams have wings and feet, "+
                      "and journeys to take.\n",
      }));
      set_short("Fire Giant");
      set_long("A large, broad humanoid. His skin is coal black, "+
               "his hair is flaming red\nand his eyes are a deep, "+
               "menacing ochre.\n");
      add_class("fighter");
    break;

    case 1:
      set_name("frost giant");
      set_race("giant");
      set_gender(1);
      set_level(20);
      set_magic_resist(30);
      add_spell_immune("cold");
      load_chat(10, ({
       "Giant says:  I will show you fear in a handful of dust.\n",
       "Giant says:  You only know a heap of broken images.\n",
       "Giant says:  Look into the heart of light, the silence.\n",
      }));
      set_short("Frost Giant");
      set_long("A very large humanoid creature with an ivory skin color, "+
               "blue-white hair\nand pale blue eyes.\n");
      add_class("fighter");
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

