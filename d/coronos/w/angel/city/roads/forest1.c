#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a tree lined road");

  set_long(
  "Tall trees line the sides of the road and continue down a trail \n"+
  "to the south. To the north, the farming land seems drier and     \n"+
  "sparsely populated.\n");

  set_weather(1,0,0);
  set_exits(({
	PATH+"wild1", "east",
	PATH+"clearing", "west",
  }));

  set_items(({
	"land#farming land",
	"The farm land looks drier and is obviously less irrigated than\n"+
	"much of the rest of the land hereabouts",

	"road",
	"The road is well travelled and made from stone and mortar",

	"trail#south",
	"The south trail seems to lead to a very large homestead",

	"trees#oak trees",
	"They are oak trees and, given their size, appear to be hundreds\n"+
	"of years old", 

	"homestead#large homestead",
	"The homestead is nearly three stories tall and is very wide.\n"+
	"Either several families live here, or a rich merchant\n",

	"chimneys",
	"Several chimneys tower from the tops of the large homestead",

	"smoke",
	"The smoke rises up from the chimney into the sky, \n"+
	"mixing with the clouds above",
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a horse\n",
 }));


  set_smell("You can smell smoke\n");
  set_listen("You hear birds twittering in the oak trees\n");
} 


