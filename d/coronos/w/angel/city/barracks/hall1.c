#include <mudlib.h>

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the north gate of ille coronos");

  set_long(
"A grand stairway winds its way downward to the Great North Gate, \n"+
"while a long stone corridor marks the way to the barrack rooms   \n"+
"of the 12th garrison.\n");


  set_items(({
	"torch#torches",
"Held by bronzed sconces they flicker in the slight breeze",

	"sconces#brackets",
"They appear to be made from bronze, and are fastened to the walls\n"+
"on each side of the arrow slits.",

	"arrow slit#arrow slits",
"The arrow slits are one means of defending the Great North Gate. The \n"+
"burning torches give archers the opportunity to use flaming arrows   \n"+
"against any foe who dares to lay seige to the city",

	"stairway#stairs#staircase",
"A tall stairway, made from a hard dull-yellow stone. The scale of the  \n"+
"stairway is rather impressive. It could hold many dozen men if the city\n"+
"were to be attacked",
  }));

  set_weather(2, 1, 0);

  set_exits(({
	"d/coronos/w/angel/city/barracks/stairs", "down",
	"d/coronos/w/angel/city/barracks/guild", "east",
  }));
}

