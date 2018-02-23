#include <mudlib.h>
#include "paths.h"


inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the highway north of ille coronos");

  set_long(
"You find yourself in the middle of a wide road, leading north and.\n"+
"south. To the east and west you see vast tracks of well tended crops\n"+
"and empty fields of grazing cattle, with a stone aqueduct behind them.\n"+
"The evil presence of Darken Mountain still looms ahead. ");

  set_day_desc(                                           "A few tall\n"+
"lanterns by the roadside wait til evening when they will be lit.\n");


  set_night_desc(                                         "A few tall\n"+
"lanterns by the roadside are lit to show travellers the way to the  \n"+
"city of Ille Coronos to the south.\n");

  set_weather(3,0,0);
  set_exits(({
        PATH+"road1", "south",
        PATH+"road3", "north",
  }));


  set_items(({
	"lanterns#lantern",
	"They stand nearly 10 feet tall and are made from iron.",

	"road#pavement",
	"The road is made from pebbles and rocks, fused together with\n"+
	"a grey mortar. It looks well travelled",

	"darken mountain#mountain",
	"Darken Mountain is said to be the home of the drow",

	"south#city#ille coronos",
	"The walls of Ille Coronos seem a few miles away",

	"walls",
	"The walls are grey brown in colour and were made with the\n"+
	"assistance of dwarven stonemasons nearly 20 years ago.\n"+

	"cloud#clouds", "They are fluffy clouds. One looks like an elephant\n",

	"sea",
	"You can't see it from here, but you can smell the salt air",
 }));


  set_smell("The air smells of salt coming from the sea to the south.\n");
  set_listen("You hear the faint sound of the bustle of the city.\n");

} 
