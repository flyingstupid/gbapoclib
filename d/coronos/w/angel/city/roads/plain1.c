#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a grassy plain");

  set_long(
  "A large open, dry and grassy plain extends north and south.\n"+
  "A dirt trail leads back to a road to the south.\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain2", "north",
	PATH+"clearing", "south",
  }));

  set_items(({
	"road",
	"A wide and well used road",

	"trail",
	"The trail leads to a road",

	"grass#grassy plain#plain",
	"Dry grass as tall as a halfling extends across a wide open plain",

	"road",
	"The road is well travelled and made from stone and mortar",

	"forest#scanthian",
	"The forest is made of large oak trees, thousands of years old. \n"+
	"It is the home of the wood elves who call this place Scanthian",

	"trees#oak trees",
	"They are oak trees and, given their size, appear to be hundreds\n"+
	"of years old", 
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a dingo pup\n",
 }));


  set_smell("You can smell smoke to the east\n");
  set_listen("You hear a few possums moving in the canopy above\n");
} 


