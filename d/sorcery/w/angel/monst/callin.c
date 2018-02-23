#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("callin");
  set_short("Callin Steele");
  set_long(
	"Callin is the young son of Azzel Steele, one of the members of the\n"+
"Council of the Nine on the Isle of Sorcery. He is about nine years\n"+
"old, and has a happy face. It is as if he doesnt have a care in  \n"+
"the world. If he is anything like his father, even in his young   \n"+
"age he is probably a master wizard\n");

  set_level(5);
  add_class("fighter");
  add_class("mage");

  load_spells(50, ({ 
	"magic missile",
	"rope trick",
	"shield",
	"chill touch",
  }));

  load_chat(5, ({
	"Callin asks: Have you seen my daddy?\n",
	"Callin says: My daddy is on the Council of the Nine.\n",
	"Callin smiles happily.\n",
	"Callin laughs at a joke, told only to himself.\n",
 }));

  load_a_chat(5, ({
	"Callin exclaims: Ouch! That hurts!\n",
	"Callin bursts into tears.\n",
	"Callin says: Im telling my daddy on you.\n",
	"Callin tries to run away.\n",
  }));
  set_alignment(200);
  set_gender(1);
  set_wimpy(100);
}

