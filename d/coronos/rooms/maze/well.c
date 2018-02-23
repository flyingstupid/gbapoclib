#include "path.h"
#include <mudlib.h>

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("a dark tunnel");
  set_long(
	"Water drips constantly from the walls into a small trough \n"+
	"set into the middle of this dark place, echoing through   \n"+
	"this dark and cold place. A small spring seems to bubble  \n"+
	"out of the centre of the room, and then down the trough   \n"+
	"into the darkness beyond.\n");

  set_items(({
	"trough", 
	"The trough is a shallow recess in the centre of the well's \n"+
	"floor, and extends northward into the darkness.\n",

	"water", 
	"Cold water drips from the walls, making this an uncomfortable \n"+
	"place to rest.",

	"spring",
	"The spring water bubbles up from the centre of the well floor",

	"floor",
	"The well floor has a large crack in the centre through which \n"+
	"a natural cold water spring bubbles",
	"bubbles", " . . o O 0 0",
	"darkness", "You can't see through it!\n",
  }));


  set_exits(({
        PATH+"maze1", "north",
        "d/coronos/w/darkness/mainst2", "up",
  }));

  set_climb(5);
  set_fall_dam(5);


  set_weather(0, 1, 0);
  set_listen("You can hear dripping water coming from the north.\n");
}
