#include <mudlib.h>
#include "paths.h"

inherit ROOM;


void reset(status arg) {
  object farmer;

  if(!present("farmer")) {
    farmer = clone_object(MONST+"farmer");
    move_object(farmer, this_object());
  }

  if(arg) return;

  set_short("a road through the farming lands");

  set_long(
"Small country homesteads dot the country side amid fields of \n"+
"wheat and barley. \n");


  set_weather(1,0,0);
  set_exits(({
	PATH+"hump", "east",
	PATH+"forest1", "west",
  }));

  set_items(({
	"fields",
	"The fields surround small homesteads",

	"wheat#barley",
	"It looks good enough to harvest",

	"homesteads",
	"The homesteads are where the farmers and their families live.\n"+
	"Thin plumes of smoke rise up from their chimneys",

	"chimneys",
	"They are made from stone",

	"smoke",
	"The smoke rises up into the sky, mixing with the clouds above",
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a boat\n",
 }));


  set_smell("You can smell smoke\n");
  set_listen("You hear birds twittering in the trees\n");
} 


