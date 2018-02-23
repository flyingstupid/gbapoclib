#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("Main Street");
    set_long(
      "Main Street runs west and east through the main core of Ille Coronos \n"+
      "and is lined on either side with trees and bushes. To the west a \n"+
      "Residential Street heads north, whereas to the east West Temple \n"+
      "leads back to the south.");
    set_day_desc(
      "\n");
    set_night_desc(
      " A pair of lamps burn brightly along the street.\n");
    set_items(({
	"road#street",
	"You are standing on Main Street.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes seem to be in good health.\n",
	"grass",
	"The grass is green and healthy.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"trees#tall trees#tree",
	"The tall trees block the view of the temple to the southeast \n"+
	"as well as the homes to the north.\n",
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
	"/d/coronos/w/vorax/res1","west",
        "/d/coronos/w/alena/ille/m_4", "east",
      }));
}
