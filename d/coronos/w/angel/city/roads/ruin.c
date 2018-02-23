#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("an old ruined building");

  set_long(
  "From the fire damage in this building, it burnt down many years ago.\n"+
  "Now, it no longer has a ceiling or door. It is little more than a shell.\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain4", "south",
	PATH+"plain8", "north",
	PATH+"plain9", "east",
	PATH+"plain3", "west",
  }));

  set_items(({
	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is northward",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide open plain",

        "cloud#clouds",
        "They are fluffy clouds. One looks like an elf\n",
  }));


  set_listen("You hear the wind blowing in the tall grass\n");
}                                 



