/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1239) );
    set_long( get_long_by_id(1239) );


    set_exits(({
        AREA_PATH + "forest_1188.c", "northwest",
        AREA_PATH + "forest_1189.c", "north",
        AREA_PATH + "forest_1190.c", "northeast",
        AREA_PATH + "forest_1238.c", "west",
        AREA_PATH + "forest_1240.c", "east",
        AREA_PATH + "forest_1288.c", "southwest",
        AREA_PATH + "forest_1289.c", "south",
        AREA_PATH + "forest_1290.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1239 ) );
}

