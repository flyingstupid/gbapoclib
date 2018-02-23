/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1496) );
    set_long( get_long_by_id(1496) );


    set_exits(({
        AREA_PATH + "forest_1445.c", "northwest",
        AREA_PATH + "forest_1446.c", "north",
        AREA_PATH + "forest_1447.c", "northeast",
        AREA_PATH + "forest_1495.c", "west",
        AREA_PATH + "forest_1497.c", "east",
        AREA_PATH + "forest_1545.c", "southwest",
        AREA_PATH + "forest_1546.c", "south",
        AREA_PATH + "forest_1547.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1496 ) );
}

