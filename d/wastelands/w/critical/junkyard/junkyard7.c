#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Path to the yard");
    set_long(
        "The piles of junk can be seen just north of your position. They seem to be set into\n"+
        "two large distinct piles. A path between the two large piles sets directly ahead of you.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard2","south",
	"d/wastelands/w/critical/junkyard/junkyard10","north"}));
}