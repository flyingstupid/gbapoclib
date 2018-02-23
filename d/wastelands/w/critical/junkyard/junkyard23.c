#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("A corner in the junk stacks");
    set_long(
        "A corner of the stacks. It allows you to see a few of the piles\n"+
        "from where your standing.\n"   
        );
    set_exits(({
	"d/wastelands/w/critical/junkyard/junkyard24","east",
    "d/wastelands/w/critical/junkyard/junkyard18","south",
    }));
}