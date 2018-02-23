#include <mudlib.h>
#include "paths.h"

inherit ROOM;

object giant;
int i;

void reset(status arg) {

  if(!giant) {
    for(i=0; i<3; i++) {
      giant = clone_object(MONST+"f_giant");
      move_object(giant, this_object());
    }
  }

  if(arg) return;

  set_short("a grassy plain");

  set_long(
  "This area is rocky and barren. There are several sets of gigantic-sized \n"+
  "footprints here, moving toward the east.\n");


  set_weather(1,0,0);

  set_exits(({
	PATH+"giant_lair", "east",
  }));

  set_items(({
	"footprints",
	"You summise that there are roughly three sets of \n"+
	"gigantic-sized footprints",


	"grass#grassy plain#plain",
	"Dry grass as tall as a halfling extends across a wide open plain",
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a tankard of ale\n",
 }));


  set_smell("You can smell giants to the east\n");
  set_listen("You hear a loud noises from the west\n");
} 


