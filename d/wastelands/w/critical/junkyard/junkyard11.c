#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("A path through the stacks");
    set_long(
        "A path through the junk yard. There are two trails that lead\n"+
        "east and west. Heavy foot tracks lead in both directions and there\n"+
		"are tracks and trails from something having been dragged from one of\n"+
		"the huge piles of junk.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard10","west",
	"d/wastelands/w/critical/junkyard/junkyard12","east"}));
}