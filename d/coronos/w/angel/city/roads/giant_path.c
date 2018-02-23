#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a grassy plain");

  set_long(
  "A large open, dry and grassy plain extends in all directions.\n"+
  "Gigantic humanoid footprints lead to the west.\n");


  set_weather(1,0,0);

  set_exits(({
	PATH+"big_tree", "east",
	PATH+"giant_lair", "west",
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


