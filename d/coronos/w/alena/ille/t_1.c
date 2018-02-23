#include <mudlib.h>
inherit ROOM;

void reset (status arg){

    if (arg) return;

    set_short("West Temple");
    set_long(
      "Alternating red and brown brick make up the road under foot and \n"+
      "bushes and small trees form barriers on both sides of West Temple. \n"+
      "A huge temple can be seen to the southeast, through larger and more \n"+
      "mature oak trees.");
    set_day_desc(
      " The temple's top shines in the sunlight.\n");
    set_night_desc(
      " A tall lamp burns brightly, lighting up the night.\n");
    set_items(({
	"road#street",
	"West Temple is made up of red and deep brown brick.\n",
	"bricks#brick#red bricks",
	"These are smooth red and brown bricks that pave the road.\n",
	"bush#bushes",
	"These bushes seem to be in good health.\n",
	"grass",
	"The grass is green and healthy.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"trees#tree#oak tree#oak trees",
	"The trees are small except for the more mature trees closer to the \n"+
	"temple to the southeast.\n",
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
	"/d/coronos/w/alena/ille/m_3","north",
	"/d/coronos/w/alena/ille/t_2","south",
      }));
}
