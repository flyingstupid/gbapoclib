#include <mudlib.h>
inherit ROOM;

void reset (status arg){

    if (arg) return;

    set_short("the intersection of West and South Temple");
    set_long(
      "South Temple meets up with West Temple here, just southwest \n"+
      "of the great temple of Ille Coronos. Red and brown brick pave \n"+
      "the street with deep green bushes and tall oak trees on either \n"+
      "side.  A large wall runs west to east, forming an impassable \n"+
      "barrier to the south.");
    set_day_desc(
      " Shadows from the oak trees, and the wall, \n"+
      "fall upon the pavement below.\n");
    set_night_desc(
      " Light beams down from the tall lamp.\n");
    set_items(({
	"road#street",
	"West Temple runs to the north where South Temple \n"+
	"leads to the east.\n",
	"bricks#brick#red bricks",
	"These are smooth red and brown bricks that pave the road.\n",
	"bush#bushes",
	"They form a barrier to the east, seemingly boxing in the temple.\n",
	"grass",
	"The grass is green and healthy.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"trees#tree#oak tree#oak trees",
	"The trees are small except for the more mature trees closer to the \n"+
	"temple to the northeast.\n",
	"temple",
	"It is hidden behind the trees and bushes.\n",
      }));
    set_day_items(({
	"lamp post#lamp posts",
	"This lamp post is made of iron and engraved with \n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They are currently unlit.\n", 
      }));  
    set_night_items(({
	"lamp post#lamp posts",
	"This lamp post is made of iron and is engraved with very \n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They burn brightly, illuminating the road.\n",
      }));
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/alena/ille/t_2","north",
	"/d/coronos/w/alena/ille/t_4","east",
      }));
}
