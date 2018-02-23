#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Inside the Junkyard's Main Office");
    set_long(
        "Ruined carpets and wallpaper is the first thing you see when you enter the room,\n"+
        "next is the long counter that sits directly in front of the door. Behind the counter."+
		"Are various junky furniture selections along with empty boxes of all kinds. Its pretty\n"+
        "obvious that there were folks living here recently. There are three rooms that lead from\n"+
        "this one.\n");
        
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard6","north",
    "d/wastelands/w/critical/junkyard/junkyard5.c", "northwest",
	"d/wastelands/w/critical/junkyard/junkyard4.c", "west",
	"d/wastelands/w/critical/junkyard/junkyard2.c", "east"}));
}