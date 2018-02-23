#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("A path through the stacks");
    set_long(
        "A corner of the massive junkyard. There are two trails that lead\n"+
        "north and east. Heavy foot tracks lead in both directions and there\n"+
		"are tracks and trails from something having been dragged from one of\n"+
		"the huge piles of junk.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard13","north",
	"d/wastelands/w/critical/junkyard/junkyard9","east"}));
}