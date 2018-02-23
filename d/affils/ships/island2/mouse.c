#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mouse");
  set_plural("mice");
  set_short("A field mouse");
  set_long(
	"This small mouse is grey and very cute, and lives in \n"+
	"the long grasses of the fields around the grove.\n");

  set_level(1);
  set_gender(1);
  set_race("mouse");

  load_chat(5, ({
	"Mouse squeaks.\n",
	"Mouse looks around for food.\n",
	"Mouse scurries around.\n",
	"Mouse cleans his tail.\n",
	"Mouse looks at you with big eyes.\n",
	"Mouse squeaks happily.\n",
  }));

  set_wimpy(20);
  set_dead_ob(this_object());
}

void monster_died() {
  tell_room(environment(),
	"Mouse cries out in anguish!\n");
}


 
