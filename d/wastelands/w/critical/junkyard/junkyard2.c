#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Outside of the Junkyard Main Office");
    set_long(
        "A large damaged building stands to the west of here. Beaten and battered, this\n"+
        "building has seen better days, however now it lacks an outside door and windows. A\n"+
        "series of spraypaint lists several gang territories, however now it seems to read \n"+
        "BEWARE OF DOG and something about Jack the Ripper.");
        
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard7","north",
    "d/wastelands/w/critical/junkyard/junkyard1.c", "south",
	"d/wastelands/w/critical/junkyard/junkyard3.c", "west"}));
}