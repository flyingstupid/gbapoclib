#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sea gull");
  set_alias("gull");
  set_short("A sea gull");
  set_race("gull");
  set_gender(2);
  set_long(
	"This small grey-white bird is here searching the shores for \n"+
	"scraps of food to eat. She looks annoyed at something and is\n"+
	"very hungry!\n");

  set_level(1);
  load_chat(3, ({
	"Sea gull squawks.\n",
	"Sea gull pecks at the ground.\n",
	"Sea gull flaps around.\n",
	"Sea gull stares at you.\n",
	"Sea gull flies into the air, and comes landing down nearby.\n",
  }));
  set_msgin("flies in");
  set_msgout("flies");

  set_attack_msg(({
	"missed", "",
	"wing buffets", "lightly",
	"wing buffets", "hard",
	"pecks", "lightly",
	"pecks", "hard!",
	"strikes", "hard with its wing",
	"strikes", "devistatingly with its wings",
  }));
}
