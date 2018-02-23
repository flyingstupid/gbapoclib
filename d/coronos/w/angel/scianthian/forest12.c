#include <mudlib.h>
#include "path.h"

inherit ROOM;

void reset(status arg) {
  string *smells;
  object ob;
  int i;

  if(arg) return;
  if(!present("mouse")) {
    for(i=0; i<4; i++) {
      ob = clone_object(MONSTER);
      ob -> set_name("field mouse");
      ob -> set_plural("field mice");
      ob -> set_short("A field mouse");
      ob -> set_long("A small grey field mouse.\n");
      ob -> set_gender(random(2) + 1);
      ob -> set_race("mouse");
      ob -> set_level(1);
      move_object(ob, this_object());
    }
  }

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
	"The forest path takes a turn southward, where the canopy darkens\n"+
	"and the light dims further. It looks very ominous\n");

  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",
  }));

  set_exits(({
	PATH+"forest1", "south",
	PATH+"forest11", "east",
  }));
}
