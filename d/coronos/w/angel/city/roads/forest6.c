#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {
  object ob;
  int i;



  if(arg) return;

  set_short("a clearing");

  set_long(
  "Many tall trees line the road, growing ever thicker toward the \n"+
  "west. The sky above is almost blocked by the spread of the     \n"+
  "canopy. \n");

  set_weather(1,0,0);
  set_exits(({
	PATH+"forest5", "east",
	PATH+"forest7", "west",
  }));

  set_items(({
	"canopy",
	"The canopy is thick at this point along the road, making it\n"+
	"almost impossible to see the sky",

	"sky",
	"You can just make out the clouds",

	"road",
	"The road is well travelled and made from stone and mortar",

	"trees#oak trees",
	"They are oak trees and, given their size, appear to be hundreds\n"+
	"of years old", 
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a chicken\n",
 }));


  set_smell("You can smell smoke to the east\n");
  set_listen("You hear a few possums moving in the canopy above\n");
} 


