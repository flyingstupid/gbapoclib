#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rat");
  set_short("a rat");
  set_race("rat");
  set_long(
	"A small and dirty rat who lives in the sewers. \n"+
	"It is likely he is a carrier of disease.\n");

  set_gender(1);
  set_level(1);

  set_attack_msg(({
	"missed", "",
	"annoys", "",
	"gnashes", "",
	"bites", "slightly",
	"scrapes", "with his claws",
	"gnaws", "with his sharp teeth",
	"bites", "hard!",
  }));

  load_chat(5, ({
	"Rat squeaks\n",
	"Rat rummages around\n",
	"Rat darts about\n",
	"Rat sniffs you\n",
	"Rat blinks\n",
	"Rat looks up at you\n",
	"Rat looks around nervously\n",
  }));

  set_msgin("scampers in");
  set_msgout("scampers");
}
