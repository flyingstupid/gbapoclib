#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_short("A green slime");
  set_long(
	"A horrible bubbling mass of green liquid, moving \n"+
	"around on the ground. It looks like it could melt\n"+
	"you to bits if it got a hold of your arms. Fortunately\n"+
	"it is only a small slime, about the size of a bear.\n");

  set_aggressive(1);
  set_gender(2);
  set_race("pudding");
  set_name("slime");
  set_level(7);
  set_attack_msg(({
	"missed", "",
	"bubbles at", "",
	"hisses at", "",
	"boils at", ""
	"blisters angrilly at",
	"spits at",
	"bubbles over at", "",
  }));

  set_msgin("sloshes in");
  set_msgout("sloshes");
  set_dead_ob(this_object());
}

void monster_died() {
  object ob;
  if(ob = present("corpse", environment())) {
    say(query_name()+" disolves away into nothingness\n");
    destruct(ob);
  }
}



 
