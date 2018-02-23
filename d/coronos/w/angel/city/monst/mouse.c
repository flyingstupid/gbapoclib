#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mouse");
  set_short("A tiny mouse");
  set_long(
	"This small mouse is grey and very cute, but in this \n"+
	"place of magic it could very well be an apprentice  \n"+
	"using a cantrip, or a punished mage now turned into \n"+
	"a small rodent.\n");
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


 
