#include "/players/relgar/private/mydefs.h"
inherit "/d/tempus/w/relgar/main.c";

reset(arg){
    if(arg)return;
    set_short("A garbage strewn street");
    set_light(1);
    set_long(
      "        You are walking along one of the roads in the town. There are several\n"+
      "buildings to the north and south that look boarded up to keep out \n"+
      "intruders. This section of town is in much worse shape than the rest\n"+
      "of the area. There are piles of garbage strewn about the street and \n"+
      "several beggars take up residence here.\n"
    );
    set_items(({
	"buildings#building",
	"The north or the south building?\n",
	"boards#board",
	"The boards are nailed across the windows of the buildings to the north and\n"+
	"south. They are designed to keep people out of the buildings. They appear\n"+
	"fairly new.\n",
	"garbage#piles#piles of garbage#pile",
	"The piles of garbage here are mostly animal offal and rotting, maggot \n"+
	"infested bread. Anything else would have been carried off by a scavenger,\n"+
	"be that man or beast.\n",
	"beggars",
	"Unfortunately you can only look at one at a time.\n",
      }));
    set_listen("You hear the sound of a dog yelping nearby.\n");
    set_smell("You can smell the acrid odor of rotting bread and day old animal\n"+
      "offal.\n");
    set_exits(({
	"d/tempus/w/relgar/road1","west",
	"room/city/nroad1","east",
      }));
} /* end of reset */
