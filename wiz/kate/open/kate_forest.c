/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;


void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( "kate's forest");
    set_long( "Kate's test forest" );


    set_exits(({}));

    set_room_type("forest");
}

