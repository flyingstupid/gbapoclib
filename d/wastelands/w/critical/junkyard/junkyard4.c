#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_room_type( "junkyard" );
    set_weather(2, 1, 0);
    set_short("Junkyard's Office Bathroom");
    set_long(
        "The area is covered in disgusting filth. Everything that should be white is instead\n"+
        "an off brown color. There is a nearly destroyed toilet along side a pedestol sink.\n");
    set_exits(({"d/wastelands/w/critical/junkyard/junkyard6","north"}));
}