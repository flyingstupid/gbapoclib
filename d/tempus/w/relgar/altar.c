inherit "players/relgar/temple/main";
#include "/players/relgar/private/mydefs.h"
static object lun;

reset (arg) {
    if(!find_living("lunatic")||!lun){
	lun = LUNATIC;
	move_object(lun,this_object());
    } /* end of make lunatic. */
    if (arg) return;
    set_exits(({
	"/players/relgar/temple/entrance","south",
      }));
    set_short("In front of the altar");
    set_long(
      "\tYou stand at the north end of the cathedral. There is a large\n"+
      "black altar in front of you. A large, upside-down cross hangs above the\n"+
      "altar. There are several rows of pews to either side of you that are\n"+
      "made of the black marble that makes up the floor tiles and columns of\n"+
      "the cathedral. You can see two doors, one to the east and one to the\n"+
      "west.\n"
    );
    set_exits(({
	"/d/tempus/w/relgar/entrance","south",
	"/d/tempus/w/relgar/tside1"  ,"east" ,
	"/d/tempus/w/relgar/tside2"  ,"west" ,
      }));
    set_light(2);
    set_items(({
	"altar#black altar","The large, black altar in front of you has some "+
	"reddish streaks in the\nmarble. You wonder why they are red. All the "+
	"marble you've ever seen\nso far has been black with white streaks.\n",
	"cross","The cross hangs up-side down over the altar. It is made of a dark "+
	"black\noak type wood. It also appears to be made of one piece of wood. "+
	"From\nall the stories you've heard, it constantly drips blood onto the "+
	"altar.\n",
	"blood","The blood is dripping constantly from the cross hanging above "+
	"the altar.\nThe blood appears to be making the marble of the altar "+
	"reddish.\n",
	"pews","The several rows on either side of you. They are made of a black "+
	"marble\nwith white veins running through it.\n",
	"tiles","The tiles here are made of a black marble and have white veins "+
	"of\nmarble running through them.\n",
	"columns","These columns rise to the ceiling and are made from the same "+
	"black\nmarble as the floor tiles and the pews.\n",
      })); /* End of Items. */
} /* end of reset */

