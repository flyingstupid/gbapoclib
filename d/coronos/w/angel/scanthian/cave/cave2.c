#include <mudlib.h>
#include "paths.h"

inherit ROOM;

object dragon;

void reset(status arg) {
  if(!dragon) {
    dragon = clone_object(MONST+"gr_dragon");
    move_object(dragon, this_object());
  }

  if(arg) return;

  set_short("a dark cave");
  set_long(
"While this part of the cave is a little smaller, the ceiling still \n"+
"extends nearly 80 feet above you. This part is a little cleaner,   \n"+
"not having nearly as many bones, but has a large depression in the \n"+
"middle. Perhaps this is where the beast that lives in these caves  \n"+
"sleeps when it is not eating?\n");


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

  set_smell("It smells like a dragon lives here.\n");

  set_exits(({
	CAVE+"cave1", "south",
  }));

}

