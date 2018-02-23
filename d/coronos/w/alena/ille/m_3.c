#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("apprentice")) {
    ob = clone_object("d/coronos/w/angel/city/monst/apprentice");
    move_object(ob, this_object());
  }
    reset_doors(arg);

    if (arg) return;

    load_door(({
	"file", "d/coronos/w/angel/city/pub/pub1",
	"direction", "north door",
	"long",
	"A large door made from oak. It bears the sign \n"+
	"  ,.,.,.,.,.,.Griffon Inn.,.,.,.,.,.,.,\n",
    }));

    set_short("Main Street");
    set_long(
      "The intersection here forms a dead end of West Temple as it connects \n"+
      "to Main Street. West Temple travles south of here and an arch stands \n"+
      "further down the street southward. Bushes line the roads and tall \n"+
      "trees also grow on both sides.");
    set_day_desc(
      "\n");
    set_night_desc(
      " The pair of lamps lining the street burn \n"+
      "brightly.\n");
    set_items(({
	"road#street",
	"This is the intersection of Main Street and West Temple.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes seem to be in good health.\n",
	"grass",
	"The grass is green and healthy.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"trees#tall trees#tree",
	"The tall trees block the view of the temple to the southeast.\n",
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
	"/d/coronos/w/alena/ille/m_4","west",
	"/d/coronos/w/alena/ille/m_2","east",
	"d/coronos/w/alena/ille/t_1","south",
      }));
}
