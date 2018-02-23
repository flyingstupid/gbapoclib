#include <mudlib.h>

inherit MONSTER;

void reset(status arg) {  
  ::reset(arg);
  if(arg) return;
  set_name("mephit");
  add_class("fighter");
    add_class("thief");
  set_short("A fire mephit");
  set_level(8);
  set_magic_resist(20);
  set_long(
	"This little creature looks like it is made from living \n"+
	"flame, yet smells like the very suphur from the pits   \n"+
	"of the Nine Hells. His teeth are big and sharp, and    \n"+
	"he looks like he would bit off your finger given the   \n"+
	"chance.\n");
  set_race("demon");
  set_gender(1);
  set_alignment(-100);
  load_chat(5, ({
	"Mephit grumbles.\n",
	"Mephit gurgles.\n",
	"Mephit dances around.\n",
	"Mephit says: Eat your brains, I will.\n",
	"Mephit says: Pbzzzttt!\n",
	"Mephit says: My master, you are not.\n",
	"Mephit asks: Free me, you will?\n",
	"Mephit says: Treasure, will I give you.\n",
	"Mephit glares at you.\n",
	"Mephit wanders around.\n",
	"Mephit exclaims: Away go you!\n",
	"Mephit asks: Take me back to the Hells, will you?\n",
  }));

  load_a_chat(10, ({
	"Mephit says: My master will kill you.\n",
	"Mephit says: My master will pull off your head.\n",
	"Mephit says: My master is bigger than you.\n",
	"Mephit says: Eat you I will.\n",
  }));
}
