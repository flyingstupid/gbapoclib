/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1372) );
    set_long( get_long_by_id(1372) );


    set_exits(({
        AREA_PATH + "forest_1321.c", "northwest",
        AREA_PATH + "forest_1322.c", "north",
        AREA_PATH + "forest_1323.c", "northeast",
        AREA_PATH + "forest_1371.c", "west",
        AREA_PATH + "forest_1373.c", "east",
        AREA_PATH + "forest_1421.c", "southwest",
        AREA_PATH + "forest_1422.c", "south",
        AREA_PATH + "forest_1423.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1372 ) );
}

