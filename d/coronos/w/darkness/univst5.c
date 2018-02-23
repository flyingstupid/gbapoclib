#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("University Street");
    set_long(
      "University Street has been paved with carefully placed stones \n"+
      "and its edges lined with neatly trimmed and well kept bushes.\n"+
      "A few young trees stand behind a group of wooden benches. Just to \n"+
      "the sides of the benches stand a pair of elegant lamp posts.");
    set_day_desc(
      "\n");
    set_night_desc(
      " The \n"+
      "pair of lamps burn brightly to light the street.\n");
    set_items(({
	"road",
	"This is University Street.  It is paved with grey bricks.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes are well trimmed and in healthy condition.\n",
	"grass",
	"The grass is green and healthy.\n",
	"tree#trees",
	"These are young saplings that have recently been planted.\n",
	"bench#benches#wooden benches",
	"These wooden benches look brand new.  They are made from wood, and\n"+
	"held together with an iron frame.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
      }));
    set_day_items(({
	"lamp post#lamp posts",
	"This pair of lamp posts are made from iron, and are engraved with\n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They are currently unlit.\n", 
      }));  
    set_night_items(({
	"lamp post#lamp posts",
	"This pair of lamp posts are made from iron, and are engraved with\n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They burn brightly, illuminating the road.\n",
      }));
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/eastrd3", "west",
	"/d/coronos/w/darkness/univst4", "east",
      }));
}
