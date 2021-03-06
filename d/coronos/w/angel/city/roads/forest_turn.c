#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a sloping road");

  set_long(
  "The road slopes down to the south, moving around the Scanthian forest\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"forest10", "northeast",
  }));

  set_items(({

	"trail",
	"A wide dirt trail leads into the dark forest",

	"canopy",
	"The canopy is thick at this point along the road, making it\n"+
	"almost impossible to see the sky",

	"sky",
	"You can just make out the clouds",

	"road",
	"The road is well travelled and made from stone and mortar",

	"forest#scanthian",
	"The forest is made of large oak trees, thousands of years old. \n"+
	"It is the home of the wood elves who call this place Scanthian",

	"trees#oak trees",
	"They are oak trees and, given their size, appear to be hundreds\n"+
	"of years old", 
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a fish\n",
 }));


  set_smell("You can smell smoke to the east\n");
  set_listen("You hear a few possums moving in the canopy above\n");
} 


