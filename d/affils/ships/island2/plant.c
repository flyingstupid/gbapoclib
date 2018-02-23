#include <mudlib.h>
inherit MONSTER;


void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("venus fly trap");
  set_alias("trap");
  set_race("plant");
  set_alt_name("venus");
  set_gender(2);
  set_al(-25);
  set_level(1);
  set_hp(50);
  set_ac(3);
  set_wc(5);
  set_short("A venus fly trap");
  set_long(
	"This is a huge plant which has apparently grown right in \n"+
	"the middle of the path here. Perhaps it is the same druid\n"+
	"who made the newbie eating plant who put it here?!\n");
  load_chat(9, ({ "Venus fly trap leans towards you hungrily.\n",
	"Venus fly trap looks at you hungrily.\n",
	"Venus fly trap licks its lips and smiles at you hungrily.\n",
	"Venus fly trap moves closer towards you.\n"
  }));

  load_a_chat(9, ({ "Venus fly trap flaps its leaves about frantically!\n",
	"Venus fly trap tries to grow legs to run away\n",
	"Venus fly trap attempts to yell for help...but fails.\n"
  }));

  set_attack_msg(({
	"smashes",	"with her leaves",
	"eats",		"alive",
	"munches",	"on the leg",
	"licks",	"across the chest",
	"pokes",	"with her leaves",
	"grazes",	"with her plant teeth",
	"brushes",	"across the body"
  }));
}
