/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(882) );
    set_long( get_long_by_id(882) );


    set_exits(({
        AREA_PATH + "forest_831.c", "northwest",
        AREA_PATH + "forest_832.c", "north",
        AREA_PATH + "forest_833.c", "northeast",
        AREA_PATH + "forest_881.c", "west",
        AREA_PATH + "forest_883.c", "east",
        AREA_PATH + "forest_931.c", "southwest",
        AREA_PATH + "forest_932.c", "south",
        AREA_PATH + "forest_933.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 882 ) );
}

