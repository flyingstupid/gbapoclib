/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1107) );
    set_long( get_long_by_id(1107) );


    set_exits(({
        AREA_PATH + "forest_1056.c", "northwest",
        AREA_PATH + "forest_1057.c", "north",
        AREA_PATH + "forest_1058.c", "northeast",
        AREA_PATH + "forest_1106.c", "west",
        AREA_PATH + "forest_1108.c", "east",
        AREA_PATH + "forest_1156.c", "southwest",
        AREA_PATH + "forest_1157.c", "south",
        AREA_PATH + "forest_1158.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1107 ) );
}

