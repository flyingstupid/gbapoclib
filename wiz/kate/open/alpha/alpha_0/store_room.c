//
//  wiz/kate/open/store_room.c
//  Second Chance
//



#include <mudlib.h>

inherit STORE_ROOM;


void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Store Room");
    set_long(
             " Store Room \n"+
             "This is a store room where items can be purchased and sold. \n");
    
    set_room_type("building");

}
