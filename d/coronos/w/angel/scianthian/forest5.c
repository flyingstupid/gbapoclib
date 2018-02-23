#include <mudlib.h>
#include "path.h"

inherit ROOM;

void reset(status arg) {
  string *smells;

  if(arg) return;

  smells = ({
	"The air is fresh and cool.\n",
	"The air is cold against your skin.\n",
	"The cool air gives you goosebumps.\n",
	"The air smells of pine.\n",
	"The air smells sweet and crisp.\n",
	"The air smells fresh.\n",
  });

  set_smell(smells[random(sizeof(smells)-1)]);
  set_short("scianthian forest");

  set_long(
	"The game trail continues to meander its way through deep into \n"+
	"the dark canopy of the forest. A few rocks lay scattered around\n"+
	"marking some long past fire.\n");

  set_weather(1, 1, 0);
  
  set_items(({
	"rocks",
	"The rocks form a small, broken circle, where some past adventurer\n"+
	"perhaps stopped to light a fire and camp during the night.\n",

	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",
	"trail#game trail",
	"You spy a few prints on it",
	"prints", "They are of small animals",
  }));

  set_exits(({
	PATH+"forest8", "west",
	PATH+"forest4", "east",
  }));
}
