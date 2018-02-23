#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a mountain pass");

  set_long(
  "The face of Darken Mountain looms before you like an ominous \n"+
  "black obelisk. A small dark cave entrance, half burried by rock\n"+
  "stands before you, the open grassy plains behind you.\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain11", "south",
	UNDERDARK+"cliff2", "north",
  }));

  set_items(({
	"rocks",
	"They look like they have come to rest here after a rock slide",

	"cave#entrance",
	"It looks dark and foreboding",

	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is right before you\n"+
	"It looks very intimidating",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide \n"+
	"open plain to the south",

        "cloud#clouds",
        "The clouds look dark and ominous.\n",
  }));


  set_listen("You hear the whispers of dark and evil things "+
  "inside the cave... \n");
}

                                 
