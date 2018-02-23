/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2330) );
    set_long( get_long_by_id(2330) );


    set_exits(({
        AREA_PATH + "forest_2279.c", "northwest",
        AREA_PATH + "forest_2280.c", "north",
        AREA_PATH + "forest_2281.c", "northeast",
        AREA_PATH + "forest_2329.c", "west",
        AREA_PATH + "forest_2331.c", "east",
        AREA_PATH + "forest_2379.c", "southwest",
        AREA_PATH + "forest_2380.c", "south",
        AREA_PATH + "forest_2381.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2330 ) );
}

