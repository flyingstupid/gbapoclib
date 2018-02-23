#include <mudlib.h>
#include "paths.h"


inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a road leading north out of Ille Coronos");

  set_long(
"A long winding road leads south toward the city of Ille Coronos, capital\n"+
"of the Coronos Empire and home to its emperor. The north road is well   \n"+
"paved and meanders toward the ever looming Darken Mountain.\n");

  set_weather(3,4,3);
  set_exits(({
        PATH+"road2", "north",
	NEWBIE+"road1", "south",
  }));


  set_items(({
	"road#pavement",
	"The road is made from pebbles and rocks, fused together with\n"+
	"a grey mortar. It looks well travelled",

	"darken mountain#mountain",
	"Darken Mountain is said to be the home of the drow",

	"south#city#ille coronos",
	"You can make out the magestic north walls of Ille Coronos \n"+
	"and the city guards that patrol its tops",

	"walls",
	"The walls are grey brown in colour and were made with the\n"+
	"assistance of dwarven stonemasons nearly 20 years ago.\n"+
	"From here you can make out the city guard patrolling its tops.\n"+
	"The walls look very well protected",

	"guard#guards#city guards",
	"They are wearing black leather armour and white surcoats.\n"+
	"One of them seems to spot you and notifies the others.\n",

	"surcoat#surcoats#armour",
	"You can't see them from here",

	"cloud#clouds", "They are fluffy clouds.\n",

	"sea",
	"You can't see it from here, but you can smell the salt air",
 }));


  set_smell("The air smells of salt coming from the sea to the south.\n");
  set_listen("You hear the bustle of the city.\n");

} 
