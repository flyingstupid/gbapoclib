inherit "players/relgar/temple/main";
#include "/players/relgar/private/mydefs.h"

reset (arg) {
    reset_doors(arg);
    load_door(({
	"destination","d/tempus/w/relgar/pchamb11",
	"direction","east door",
	"long","An ornately carved, red oak door.\n",
	"key id","iron key",
	"lock id","iron lock",
	"lock description","The lock is a fairly mundane, iron lock.\n",
	"door number",1,
      }));

    if (arg) return;
    set_short("East of the altar");
    set_light(2);
    set_exits(({
	"d/tempus/w/relgar/tapod","north",
	"d/tempus/w/relgar/altar","west" ,
	"d/tempus/w/relgar/tside4","south",
      }));
    set_long(
      "\tFrom this side of the cathedral you can see the marble pews to\n"+
      "your southwest and the altar to the west. Here there is a small stand with\n"+
      "a bowl of water perched on the top. There is an aisle leading south along\n"+
      "the eastern wall of the cathedral. The columns here are made of the black\n"+
      "marble that is found throughout the cathedral. To the north you can see \n"+
      "one of the podiums that the priests give sermons from.\n"
    );
    set_items(({
	"aisle","The aisle leads south along the eastern wall of the cathedral.\n",
	"pews","The marble pews stand in silent rows to your southwest. They are made "+
	"of\nblack marble and have veins of white running throughout.\n",
	"altar","You can get a better look to the west.\n",
	"wall#eastern wall","The eastern wall of the cathedral forces people to enter "+
	"through the front\ndoor instead of wherever they choose.\n",
	"stand","The stand is made entirely of beaten silver. The bowl at the top is "+
	"supported\nby two helix-shaped strands of silver that weave up from the "+
	"floor.\n",
	"bowl","The bowl at the top is made entirely of copper. Inside the bowl is a "+
	"clear\nliquid.\n",
	"unholy water#water#clear liquid#liquid","The liquid appears to be some sort "+
	"of unholy water.\n",
      }));

} /* end of reset */

