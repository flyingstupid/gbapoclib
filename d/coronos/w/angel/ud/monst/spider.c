#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("spider");
  set_alignment(-20);
  set_aggressive(1);
  set_plural("spiders");
  set_race("spider");
  set_gender(2);
  set_level(2);
  set_short("a giant spider");
  set_long(
	"With large hairy legs and a body nearly two feet across,\n"+
	"this spider is one of the most deadly of it's kind. The \n"+
	"spider looks very hungry.\n");
  set_heart_ob(this_object());
  set_attack_msg(({
	"brushes",	"with her claw",
	"scrapes", 	"with her claw",
	"cuts",    	"with her fangs",
	"gouges",	"with her fangs",
	"bites",	"with her fangs",
	"stabs",	"with her fangs",
	"bites deeply",	"with her fangs",
  }));
}

void monster_heart_beat() {
  object ob, poison;
  if(ob=query_primary_attack()) {
    if(!present(ob, environment())) return;
    if(random(ob->query_constitution()) > random(10)) {
      tell_object(ob, "You resist the spider's poison.\n");
      return;
    }
    if(!present("Poison", ob) && !ob->query_spell_immunity("poison")){
      poison = clone_object("obj/skills/poison");
      move_object(poison, ob);
      poison -> init();

      say("Spider poisons "+ob->query_name()+"!\n", ob);
      tell_object(ob, "Spider poisons you!\n");
    }
  }
}




    
