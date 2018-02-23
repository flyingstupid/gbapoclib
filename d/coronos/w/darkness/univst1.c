#include <mudlib.h>
#define MONST	"d/coronos/w/angel/city/monst"
inherit ROOM;

void reset (status arg){
    if (!present("citizen"))
       move_object(clone_object(MONST+"/citizen"), this_object());

    if (arg) return;

    set_short("University Street");
    set_long(
      "This road is paved with smooth, grey bricks.  The grass and bushes\n"+
      "that line the street are neatly trimmed and well kept.  The arch of\n"+
      "the University can be seen to the northeast.");
    set_day_desc(
      "  A pair of lamp posts\n"+
      "stand here.\n");
    set_night_desc(
      "  A pair of lamp posts\n"+
      "burn brightly, illuminating University Street.\n");
    set_items(({
	"road",
	"The road is paved with grey bricks.\n",
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
	"held together with an iron frame.",
	"arch",
	"The arch of the University stands tall, above the trees.\n",
  "university",
  "The great university of Ille Coronos rises high into the sky.\n",
      }));
    set_day_items(({
	"lamp post#lamp posts#posts",
	"This pair of lamp posts are made from iron, and are engraved with\n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They are currently unlit.\n", 
      }));  
    set_night_items(({
	"lamp post#lamp posts#posts",
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
	"/d/coronos/w/darkness/eastrd1", "west",
	"/d/coronos/w/darkness/univst2", "east",
	"/d/coronos/w/darkness/arch1","northeast",
      }));
}
