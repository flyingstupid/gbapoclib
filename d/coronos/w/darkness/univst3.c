#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("University Street");
    set_long(
      "Well trimmed grass and bushes continue to line the edges of \n"+
      "University Street, which itself is paved with smooth bricks \n"+
      "which have been walked upon many a time. Benches line the \n"+
      "street and the arch of the University can be seen towards \n"+
      "the north.  A lamp post stands on the west side of the road.\n");
    set_night_desc(
      "The lamp post burns brightly, illuminating University Street.\n");
    set_items(({
	"road",
	"This is University Street.  It is paved with grey bricks.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes are well trimmed and in healthy condition.\n",
	"grass",
	"The grass is green and healthy.\n",
	"arch",
	"The arch of the University rises to the north.\n",
	"bench#benches#wooden benches",
	"These wooden benches look brand new.  They are made from wood, and\n"+
	"held together with an iron frame.\n",
      }));
    set_day_items(({
	"lamp post#lamp",
	"This lamp post is made from iron, and is engraved with intricate\n"+
	"designs.  It has a cylindrical top that house the oil and wick.\n"+
	"It is currently unlit.\n", 
      }));  
    set_night_items(({
	"lamp post#lamp",
	"This lamp post is made from iron, and is engraved with intricate\n"+
	"designs.  It has a cylindrical top that house the oil and wick.\n"+
	"It burns brightly, illuminating the road.\n",
      }));
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/univst2", "north",
	"/d/coronos/w/darkness/univst4", "south",
      }));
}
