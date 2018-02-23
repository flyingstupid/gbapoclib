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
  set_listen("You can hear some birds, high up in the trees.\n");

  set_short("scianthian forest");
  set_long(
"A few broken trees mark the evidence of a lightning storm that \n"+
"occured a while ago. The trees are scortched and black, but the\n"+
"surrounding area seems untouched.\n");

  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall. A few appear as \n"+
		"hit by lightning. If there was any fire, it must have \n"+
		"occured many years ago, leaving the trees dead.\n",	
	"undergrowth", "The undergrowth is very wild in this forest",

	"trail#game trail", 
	"You spot a few animal tracks",
	"tracks", "They are of small animals",
  }));
  set_exits(({
	PATH+"forest9", "south",
	PATH+"forest5", "east",
  }));
}
