/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1039) );
    set_long( get_long_by_id(1039) );


    set_exits(({
        AREA_PATH + "forest_988.c", "northwest",
        AREA_PATH + "forest_989.c", "north",
        AREA_PATH + "forest_990.c", "northeast",
        AREA_PATH + "forest_1038.c", "west",
        AREA_PATH + "forest_1040.c", "east",
        AREA_PATH + "forest_1088.c", "southwest",
        AREA_PATH + "forest_1089.c", "south",
        AREA_PATH + "forest_1090.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1039 ) );
}

