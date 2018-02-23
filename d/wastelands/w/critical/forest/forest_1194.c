/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1194) );
    set_long( get_long_by_id(1194) );


    set_exits(({
        AREA_PATH + "forest_1143.c", "northwest",
        AREA_PATH + "forest_1144.c", "north",
        AREA_PATH + "forest_1145.c", "northeast",
        AREA_PATH + "forest_1193.c", "west",
        AREA_PATH + "forest_1195.c", "east",
        AREA_PATH + "forest_1243.c", "southwest",
        AREA_PATH + "forest_1244.c", "south",
        AREA_PATH + "forest_1245.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1194 ) );
}

