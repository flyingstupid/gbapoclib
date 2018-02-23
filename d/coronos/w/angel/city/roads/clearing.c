#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a clearing");

  set_long(
  "Tall trees surround this clearing where the road is joined by a \n"+
  "dirt trail from the north.\n");

  set_weather(1,0,0);
  set_exits(({
	PATH+"plain1", "north",
	PATH+"forest1", "east",
	PATH+"forest2", "west",
  }));

  set_items(({
	"land#farming land",
	"The farm land looks drier and is obviously less irrigated than\n"+
	"much of the rest of the land hereabouts",

	"road",
	"The road is well travelled and made from stone and mortar",

	"trail",
	"The north trail seems to lead to dry grassy plains",

	"trees#oak trees",
	"They are oak trees and, given their size, appear to be hundreds\n"+
	"of years old", 
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a duck\n",
 }));


  set_smell("You can smell smoke to the east\n");
  set_listen("You hear many small birds twittering in the oak trees\n");
} 


