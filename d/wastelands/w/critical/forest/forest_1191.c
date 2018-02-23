/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1191) );
    set_long( get_long_by_id(1191) );


    set_exits(({
        AREA_PATH + "forest_1140.c", "northwest",
        AREA_PATH + "forest_1141.c", "north",
        AREA_PATH + "forest_1142.c", "northeast",
        AREA_PATH + "forest_1190.c", "west",
        AREA_PATH + "forest_1192.c", "east",
        AREA_PATH + "forest_1240.c", "southwest",
        AREA_PATH + "forest_1241.c", "south",
        AREA_PATH + "forest_1242.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1191 ) );
}

