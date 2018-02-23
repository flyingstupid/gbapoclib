#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("East Temple");
    set_long(
      "East Temple runs north and south, its walkway paved with alternating \n"+
      "red and brown brick. A large temple rises up to the west, behind tall \n"+
      "oak trees and behind a row of bushes.");
    set_day_desc(
      " The temple's top shines brightly \n"+
      "in the beaming sunlight.\n");
    set_night_desc(
      " A tall lamp burns brightly, \n"+
      "lighting up the night.\n");
    set_items(({
	"road#street",
	"East Temple is made up of red and deep brown brick.\n",
	"bricks#brick#red bricks",
	"These are smooth red and brown bricks that pave the road.\n",
	"bush#bushes",
	"They form a barrier to the west, seemingly boxing in the temple.\n",
	"grass",
	"The grass is green and healthy.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"trees#tree#oak tree#oak trees",
	"The trees are small except for the more mature trees closer to the \n"+
	"temple to the west.\n",
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
"/d/coronos/w/darkness/mainst2","north",
	"/d/coronos/w/alena/ille/t_8","south",
      }));
}
