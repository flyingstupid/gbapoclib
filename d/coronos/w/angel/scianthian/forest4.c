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


  set_listen("You can hear the song of birds in the trees above.\n");

  set_smell(smells[random(sizeof(smells)-1)]);
  set_short("scianthian forest");
  set_long(
	"Here, the forest game trails split up, heading in many directions.\n");

  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",
  }));

  set_exits(({
	PATH+"forest3", "north",
	PATH+"forest5", "west",
	PATH+"forest6", "east",
	PATH+"forest7", "south",
  }));
}
