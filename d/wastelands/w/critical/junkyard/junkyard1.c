#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Junkyard's Main Gate");
    set_long(
        "A huge chainlink fence combined with spiraling rows of razor wire surround this\n"+
        "entire facility. Piles of junk can be seen in huge mounds all over this area. A\n"+
        "small office front can be seen a little north and to the west, boarded up and in\n"+
        "general bad repair. There is a path leading into the main area to the north.");
        
    set_exits(({"d/wastelands/w/critical/forest/forest1","out",
    "d/wastelands/w/critical/junkyard/junkyard2.c", "north",}));
}