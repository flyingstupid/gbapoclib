#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("A crossroad in the junk stacks");
    set_long(
        "The path comes to a crossroads within the stacks of the junkard.\n"+
        "You can see ten huge piles that seem to stretch into infinity. The\n"+
		"junk is haphazedly stacked making the climb quite dangerous, but it\n"+
		"may have some amazing finds if you are brave enough to scale it.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard13","north",
	"d/wastelands/w/critical/junkyard/junkyard15","north",
    "d/wastelands/w/critical/junkyard/junkyard11","east",
    "d/wastelands/w/critical/junkyard/junkyard7","south",
    "d/wastelands/w/critical/junkyard/junkyard9","west",
    }));
}