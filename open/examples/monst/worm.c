#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("worm");
  set_race("worm");
  set_short("A huge earth worm");
  set_long("This worm is almost ten feet long, and must weigh about a ton!\n"+
	   "It simply seems to be searching for food along the path here.\n");
  set_level(5);
  set_hp(80);
  set_gender(2);
  set_ac(5);
  set_wc(9);
  set_attack_msg(({
	"misses",		"",
	"squishes",		"gently",
	"squishes",		"with its tail",
	"squishes",		"with a hard blow to the head",
	"knocks",		"over, with its tail",
	"tries to bite",	"with its small teeth",
	"smashes",		"with its huge tail",
  }));
  load_chat(8, ({ "Worm looks for some food.\n",
	"Worm squishes around.\n",
	"Worm looks up at you with its tiny eyes.\n",
	"Worm squishes past you on the way to some nice plants.\n",
	"Worm smiles happily.\n",
  }));
  load_a_chat(6, ({ "Worm cries out in pain!\n",
	"Worm tries to slither away!\n",
	"Worm calls for the gardener.\n",
  }));
}
