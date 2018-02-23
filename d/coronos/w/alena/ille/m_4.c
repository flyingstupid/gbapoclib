#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("Main Street");
    set_long(
      "Just west of the intersection of West Temple and Main Street \n"+
      "the edges of the street are lined with bushes and small trees. \n"+
      "Back to the southeast you can make out a large temple through the \n"+
      "branches of the trees. Homes can be seen behind tall trees to \n"+
      "the northwest.");
    set_day_desc(
      "\n");
    set_night_desc(
      " A pair of lamps lining the street burn brightly.\n");
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
	"as well as the homes to the northwest.\n",
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
	"/d/coronos/w/alena/ille/m_5","west",
	"/d/coronos/w/alena/ille/m_3","east",
      }));
}
