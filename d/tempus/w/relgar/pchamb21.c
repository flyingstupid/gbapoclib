inherit "players/relgar/temple/main";
#include "/players/relgar/private/mydefs.h"

reset(arg){
    reset_doors(arg);
    load_door(({
	"destination","d/tempus/w/relgar/tside2",
	"direction","east door",
	"closed",
	"key id","iron key",
	"lock id","lock",
	"lock description","A fairly mundane, iron lock.\n",
	"long",
	"An ornately carved, blackened oak door.\n",
	"door number",1,
      }));
    load_door(({
	"destination","d/tempus/w/relgar/pchamb22",
	"direction","west door",
	"closed",
	"long",
	"A well crafted, old oaken door.\n",
	"key id","iron key",
	"lock id","lock",
	"lock description","A fairly mundane, iron lock.\n",
	"door number",2,
      }));
    set_light(2);
    set_short("An antechamber of the cathedral");
    set_long(
      "\tYou stand in what appears to be a private praying chamber.\n"+
      "There is a small altar here with a scaled down version of the cross\n"+
      "in the main cathedral. There are several mats laying on the floor\n"+
      "for the priest to kneel on when praying. You can see a cabinet on\n"+
      "the wall to the south. There are also shackles bracketed to the\n"+
      "wall here.\n"
    );
    set_items(({
	"cabinet",
	"The cabinet on the south wall is bloodstained and has two doors.\n",
	"shackles",
	"The shackles are firmly bolted in the wall here. They are covered with a\n"+
	"dark sticky substance that you find rather repulsive.\n",
	"altar","This small altar depicts the same gruesome scenes as the altar in\n"+
	"the main cathedral but is much smaller. It still has the cross that\n"+
	"hangs above it however.\n",
	"mats","These straw filled mats look well used. Some have blood stains on\n"+
	"the straw. Perhaps it is blood that the priest has spilt in worship\n"+
	"of his god.\n",
	"blood","The blood on the mat appears both old and dried in some places, \n"+
	"and fresh and wet in others. It seems as though the priests are\n"+
	"devout in their worship.\n",
      }));
} /* end of reset */
