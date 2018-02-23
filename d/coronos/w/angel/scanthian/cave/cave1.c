#include <mudlib.h>
#include "paths.h"


inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("a dark cave");
  set_long(
"The cave is dark and warm, with spider webs hanging from the ceiling \n"+
"that extends well over a hundred feet above you. From the bones of   \n"+
"various large animals, from sheep to horses, litter the dirt floor.\n");

  set_items(({
	"webs#web#spider webs",
	"They are sticky and white, but empty of spiders",

	"spiders",
	"Strangely enough, there don't appear to be any in the webs",

	"ceiling",
	"The dark ceiling is well over a hundred feet above you. \n"+
	"Something very large must live here",

	"bones",
	"They are scattered across the floor. You also notice \n"+
	"patches of dried and fresh blood on the ground",

	"patches#blood#patches of blood",
	"It looks as though the animal that died here lost all of\n"+
	"its blood in one foul bite!",
  }));
	

  set_weather(0, 0, 0);

  set_exits(({
	CAVE+"cave2", "north",
	PATH+"new11", "south",
  }));
}

