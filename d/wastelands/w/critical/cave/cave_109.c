/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 0, 1, 0 );
    set_short( get_short_by_id(109) );
    set_long( get_long_by_id(109) );


    set_exits(({
        
    }));

    set_room_type( get_room_scav_type( "cave", 109 ) );
}

