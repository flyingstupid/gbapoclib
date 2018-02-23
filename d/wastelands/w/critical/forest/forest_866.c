/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(866) );
    set_long( get_long_by_id(866) );


    set_exits(({
        AREA_PATH + "forest_815.c", "northwest",
        AREA_PATH + "forest_816.c", "north",
        AREA_PATH + "forest_817.c", "northeast",
        AREA_PATH + "forest_865.c", "west",
        AREA_PATH + "forest_867.c", "east",
        AREA_PATH + "forest_915.c", "southwest",
        AREA_PATH + "forest_916.c", "south",
        AREA_PATH + "forest_917.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 866 ) );
}

