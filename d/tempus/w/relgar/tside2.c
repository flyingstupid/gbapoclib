inherit "players/relgar/temple/main";
#include "/players/relgar/private/mydefs.h"

reset(arg) {
    reset_doors(arg);
    load_door(({
	"destination","/d/tempus/w/relgar/pchamb21",
	"direction","west door",
	"closed",
	"description",
	"An ornately carved, blackened oak door.\n",
	"key","None Yet",
	"door number",1,
      }));

    if(arg) return;
    set_exits(({
	"d/tempus/w/relgar/bapod", "north",
	"d/tempus/w/relgar/tside3","south",
	"d/tempus/w/relgar/altar" ,"east" ,
      }));
    set_light(2);
    set_short("West of the altar");
    set_long(
      "\tFrom this side of the cathedral you can see the marble pews to\n"+
      "the southeast and the altar to the east. There is a large, circular dais\n"+
      "here with a huge statue on it in near the west wall. There is an aisle\n"+
      "leading north and south along the western wall of the cathedral. There are\n"+
      "columns here that are made of the same marble as the rest of the cathedral"+
      ".\n"+
      "To the north you can see a podium where the priests can give a sermon from.\n"
    );
    set_items(({
	"pews",
	"The marble pews stand in silent rows to your southeast. They are made of\n"+
	"black marble and have veins of white marble running throughout.\n",
	"aisle",
	"The aisle leads south along the western wall of the cathedral.\n",
	"statue",
	"The statue is made of an almost translucent crystal that looks as though\n"+
	"it is made of solid smoke. It is a dark red color and shifts constantly.\n",
	"dais",
	"The large, circular stone dais is made of an almost translucent crystal\n"+
	"that looks to be made of solid smoke. It is a dark black color and seems\n"+
	"to shift constantly.\n",
	"columns","The columns are made of the same marble as the rest of the cathedral.\n",
	"podium",
	"You can get a better look at it if you move closer to it.\n",
      }));
} /* end of reset */
