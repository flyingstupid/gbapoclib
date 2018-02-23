#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("South Temple");
    set_long(
      "Tall trees line the northern side of the road, providing cover \n"+
      "for the temple beyond. Bushes also help to form a barrier to \n"+
      "the north and a huge wall rises up to the south and continues \n"+
      "west and east. The road is paved in red and brown brick and a few \n"+
      "have become chipped due to constant wear. A huge gate stands \n"+
      "to the southeast.");
    set_day_desc(
      " Shadows from the tall oak trees and the tall wall \n"+
      "fall upon the pavement.\n");
    set_night_desc(
      " Light beams down from the tall lamp.\n");
    set_items(({
	"road#street",
	"This is South Temple, paved with brick.\n",
	"bricks#brick#red bricks",
	"These are smooth red and brown bricks that pave the road.\n",
	"bush#bushes",
	"They form a barrier to the east, seemingly boxing in the temple.\n",
	"grass",
	"The grass is green and healthy.\n",
	"wall#south wall",
	"A tall wall that is unclimbable for even the greatest of climbers.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
	"trees#tree#oak tree#oak trees",
	"The trees are small except for the more mature trees closer to the \n"+
	"temple to the north.\n",
	"temple",
	"It is hidden behind the trees and bushes.\n",
	"gate#big gate#huge gate",
	"A huge iron gate stands in the break of the south wall.\n",
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
	"/d/coronos/w/alena/ille/t_3","west",
	"/d/coronos/w/alena/ille/t_5","east",
      }));
}
