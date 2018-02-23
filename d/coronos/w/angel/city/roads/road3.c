#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the crossroads north of ille coronos");

  set_long(
"You stand at a crossroads in the middle of a wide road. You spot \n"+
"farms and grazing land to the east and west. A small chapel for  \n"+
"travellers stands to the north, and to the south you can make    \n"+
"out the fair city of Ille Coronos. ");


  set_day_desc(                                           "A few tall"+
" lanterns by the\nroadside wait til evening when they will be lit.\n");


  set_night_desc(                                         "A few tall"+
" lanterns by the\nroadside are lit to show travellers the way to the  \n"+
"city of Ille Coronos to the south.\n");

  set_weather(3,0,0);
  set_exits(({
        PATH+"church", "north",
        PATH+"road2",  "south",
	PATH+"hump", "west",
  }));


  set_items(({
	"farms#grazing land#land#farm",
	"The farms around these parts seem to be growing wheat. A cow\n"+
	"seems to have broken through one of the fences and is eating\n"+
	"the corn from a field to the west.",

	"cow",
	"It is a milking cow and is a creamy brown colour",

	"wheat",
	"It looks ready to harvest",

	"chapel",
	"A small chapel made from wood. It is not in very good condition",

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
	"It's too far away to see very well",

	"cloud#clouds", "They are fluffy clouds. One looks like an crow\n",
 }));


  set_smell("The air smells of fresh and clean.\n");
  set_listen("You hear a cow nearby.\n");

} 
