/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1127) );
    set_long( get_long_by_id(1127) );


    set_exits(({
        AREA_PATH + "forest_1076.c", "northwest",
        AREA_PATH + "forest_1077.c", "north",
        AREA_PATH + "forest_1078.c", "northeast",
        AREA_PATH + "forest_1126.c", "west",
        AREA_PATH + "forest_1128.c", "east",
        AREA_PATH + "forest_1176.c", "southwest",
        AREA_PATH + "forest_1177.c", "south",
        AREA_PATH + "forest_1178.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1127 ) );
}

