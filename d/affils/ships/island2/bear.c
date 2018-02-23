#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bear");
  set_short("A bear cub");
  set_race("bear");
  set_alias("cub");

  set_long(
"A cute little bear cub. He seems to have lost his mother.\n");
  set_gender(1);

  set_attack_msg(({
"nudges",	"with his nose",
"bumps",	"with his nose",
"brushes", 	"with his claws",
"grazes",	"with his claws",
"bites",	"with his teeth",
"gnashes",	"with his teeth",
"smites",	"with his claws",
  }));


  load_chat(10, ({
	"Bear cries for his mother.\n",
	"Bear cries.\n",
	"Bear looks at you with big brown eyes.\n",
	"Bear cries out louder.\n",
  }));
}
