/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1141) );
    set_long( get_long_by_id(1141) );


    set_exits(({
        AREA_PATH + "forest_1090.c", "northwest",
        AREA_PATH + "forest_1091.c", "north",
        AREA_PATH + "forest_1092.c", "northeast",
        AREA_PATH + "forest_1140.c", "west",
        AREA_PATH + "forest_1142.c", "east",
        AREA_PATH + "forest_1190.c", "southwest",
        AREA_PATH + "forest_1191.c", "south",
        AREA_PATH + "forest_1192.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1141 ) );
}

