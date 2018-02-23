#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("The back of the junkyard");
    set_long(
        "From where you stand you can see the far south gate of the junkyard.\n"+
        "Various animal and robotic sounds seem to be coming from all around\n"+
        "you and deep within the stacks themselves as if they are some how inside\n"+
        "of them. You can see deep drag marks within the earth from something"+
        "large have been drug through here.\n"
        );
    set_exits(({
	"d/wastelands/w/critical/junkyard/junkyard20","south",
    "d/wastelands/w/critical/junkyard/junkyard26","east",
    "d/wastelands/w/critical/junkyard/junkyard24","west",
    }));
}