#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (!present("bastian")) {
      move_object(clone_object("d/coronos/w/angel/city/monst/guide1"),
      this_object());
    }


    if (!present("list")) {
      move_object(clone_object("objects/party_list"), this_object());
    }

    if (arg) return;

    set_short("Main Street");
    set_long(
      "Main Street runs west and east from here and is paved with smooth \n"+
      "cobblestones that have been walked over many times over the years. A \n"+
      "large gate stands to the north. Bushes line the street here, suffering \n"+
      "from lack of attention. To the north you can hear birds twittering,\n"+
      "from inside the City Gardens. To the south the great Temple of the\n"+
      "All-God stands. ");
    set_day_desc(
      "\n");
    set_night_desc(
      " The pair of lamps lining the street burn \n"+
      "brightly.\n");
    set_items(({
	"road#street",
	"This is Main Street.  It is paved with grey bricks.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes seem to be neglected.\n",
	"grass",
	"The grass is green and healthy.\n",
	"bench#benches#wooden benches",
	"These wooden benches look brand new.  They are made from wood, and\n"+
	"held together with an iron frame.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"gate#big gate",
	"A huge gate stands to the north of here.\n",
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
	"/d/coronos/w/alena/ille/m_2","west",
	"/d/coronos/w/alena/ille/mnstG","north",
        "d/coronos/w/alena/ille/temp1", "south",
	"/d/coronos/w/darkness/mainst1","east",
      }));
}
