/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1181) );
    set_long( get_long_by_id(1181) );


    set_exits(({
        AREA_PATH + "forest_1130.c", "northwest",
        AREA_PATH + "forest_1131.c", "north",
        AREA_PATH + "forest_1132.c", "northeast",
        AREA_PATH + "forest_1180.c", "west",
        AREA_PATH + "forest_1182.c", "east",
        AREA_PATH + "forest_1230.c", "southwest",
        AREA_PATH + "forest_1231.c", "south",
        AREA_PATH + "forest_1232.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1181 ) );
}

