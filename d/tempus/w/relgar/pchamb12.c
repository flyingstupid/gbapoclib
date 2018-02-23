inherit "players/relgar/temple/main";
#include "/players/relgar/private/mydefs.h"

reset (arg) {
    reset_doors(arg);

    load_door(({
	"destination","d/tempus/w/relgar/pchamb11",
	"direction","west door",
	"long","An old oaken door.\n",
	"key","None yet.",
	"door number",2,
      }));

    if (arg) return;
    set_exits(({        }));
    set_light(2);
    set_short("A priests private chamber");
    set_long(
      "\tYou have entered the private chambers of one of the priests of\n"+
      "the cathedral. In this room there are many pictures that depict demons on\n"+
      "the walls. There is a bed against the eastern wall, a desk in the south-\n"+
      "western corner of the room, and an upside-down cross hanging from the   \n"+
      "northern wall. There is also what looks like a rack in the south-eastern\n"+
      "corner.\n"
    );
    custom_exits=="";
    set_items(({
	"pictures",
	"These pictures depict absolute chaos. Millions of winged, and non-winged\n"+
	"demons, all swarming about a group of smaller demons. The smaller demons\n"+
	"seem to have a semblance of order to their fighting but are still being\n"+
	"beaten horribly by the sheer numbers of the chaotic demons.\n",
	"bed",
	"The bed against the eastern wall is well made and very utilitarian.  There\n"+
	"are no frilly adornments to the frame or anything that would be unnecessary\n"+
	"for sleeping.\n",
	"desk",
	"The desk in the northwest corner of the room has some paper and a writing\n"+
	"quill on the desk. There appears to be some writing on the paper.\n",
	"paper",
	"The writing on the paper is in some form of language which you don't\n"+
	"understand. However, you do notice the picture what appears to be a large\n"+
	"fortress that the priest has drawn on the paper.",
	"quill",
	"This quill is made from a very strange, large feather. It doesn't appear\n"+
	"to be any bird that you have seen.\n",
	"chair",
	"The chair is made of oak and has no padding whatsoever. It, like the bed,\n"+
	"appear to be only for utilitarian purposes.\n",
	"cross",
	"The small cross on the northern wall resembles the cross in the main \n"+
	"cathedral almost percfectly. However, this version does not drip blood.\n",
	"rug#hide#animal hide",
	"The rug on the floor is the complete skin of a large mammal that looks as\n"+
	"though it had six legs. The head has been removed however. It is completely\n"+
	"black in color.\n",
      }));

} /* end of reset */

