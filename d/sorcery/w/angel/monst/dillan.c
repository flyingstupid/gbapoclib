#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dillan");
  set_short("Dillan, the apprentice");
  set_race("human");
  set_level(12);
  set_alignment(-400);
  set_gender(1);

  set_long(
	"Dillan has been in the tutelage of the master of \n"+
	"the black robed mages for only a few months, but \n"+
	"he has already learned a lot from his studies.   \n");

  add_class("mage");
  add_class("cleric");

  load_chat(10, ({
	"Dillan asks: Have you come to see Archmagus Sol?\n",
	"Dillan says: If you want to join the robes, seek the Masters.\n",
	"Dillan says: Archmagus Sol is a bit bad tempered.\n",
	"Dillan studies a book.\n",
	"Dillan says: Archmagus Sol is visiting his mother, I think.\n",
	"Dillan smiles happily\n",
	"Dillan looks at you slyly.\n",
  }));
  load_spells(10, ({ "magic missile",
	"bbb", "fire rain", "acid rain",
	"monster summon 1",
	"chill touch",
	"sbf",
	"cure light wounds",
	"curse", "bless",
  }));
  set_wimpy(75);
  set_wander(50, 600);
  set_domain("sorcery/w");
}

