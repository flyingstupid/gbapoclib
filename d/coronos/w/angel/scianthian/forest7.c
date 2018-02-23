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
"A few leaves fall from the trees overhead. You have the strange \n"+
"feeling that someone is watching you from the canopy above.\n");

  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",
	"leaves", "A few green leaves, falling from the trees above",
	"trail#game trail", 
	"You spot a few animal tracks",
	"tracks", "They are of small animals",
  }));

  set_exits(({
	PATH+"forest10", "west",
	PATH+"forest4", "north",
  }));
}
