#include <mudlib.h>

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the north gate of ille coronos");

  set_long(
"A grand stairway winds its way upward to the barracks of the \n"+
"12th infantry above. Torches in sconces light the way along  \n"+
"the stairs, hung from bronze brackets aside thin arrow slits \n"+
"set into the walls. ");

  set_night_desc("The moon above sheds a little\n"+
"pale light into the area, giving it a cold and unwelcoming \n"+
"feeling.\n");

  set_day_desc("The yellow sunlight from high above\n"+
"casts rays of warm light into the area, bathing the whole \n"+
"staircase in beautiful golden rays.\n");

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
	"d/coronos/w/darkness/wallst0", "down",
	"d/coronos/w/angel/city/barracks/hall1", "up",
  }));
}



