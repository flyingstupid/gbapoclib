#include "path.h"
#include <mudlib.h>
inherit ROOM;
#include <mudlib.h>

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
  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",
	"clearing", "A small clearing in the forest",
	"mushrooms#patch#muchroom patch",
		"They look almost good enough to eat. Why don't you pick one?",
  }));

  set_exits(({
	PATH+"forest9", "west",
	PATH+"forest7", "east",
  }));

  set_long(
	"The dark forest meanders around a bend before coming to a small\n"+
	"clearing. Here, the dark canopy of the forest almost blocks out\n"+
	"your view of a small muchroom patch on the side of the road.\n");
  add_extra_object("mushroom", OBJ+"mushroom");
}

