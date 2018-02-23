#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Junkyard's Back Office");
    set_long(
        "A standard office with a massive oak desk that seems to be bolted to the floor.\n"+
        "All of the nicities are missing however. A large wall safe sits in one corner that\n"+
		"must be heavy enough that no one can move it. The ceiling here is cracked and seems\n"+
		"like it could come down at any moment.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard6","southeast"}));
}

//Add the code to put a safe into the room along with some prewar money and maybe something else fun.