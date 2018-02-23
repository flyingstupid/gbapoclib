/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(901) );
    set_long( get_long_by_id(901) );


    set_exits(({
        AREA_PATH + "forest_850.c", "northwest",
        AREA_PATH + "forest_851.c", "north",
        AREA_PATH + "forest_852.c", "northeast",
        AREA_PATH + "forest_900.c", "west",
        AREA_PATH + "forest_902.c", "east",
        AREA_PATH + "forest_950.c", "southwest",
        AREA_PATH + "forest_951.c", "south",
        AREA_PATH + "forest_952.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 901 ) );
}

