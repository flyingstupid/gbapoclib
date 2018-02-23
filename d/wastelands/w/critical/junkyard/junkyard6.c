#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Junkyard's Back Room");
    set_long(
        "Piles of junk litter the floor everywhere. There are remains of what were once shelves\n"+
        "here, now half covered in boxes and just plain junk.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard3","south"}));
}