/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(593) );
    set_long( get_long_by_id(593) );


    set_exits(({
        AREA_PATH + "forest_542.c", "northwest",
        AREA_PATH + "forest_543.c", "north",
        AREA_PATH + "forest_544.c", "northeast",
        AREA_PATH + "forest_592.c", "west",
        AREA_PATH + "forest_594.c", "east",
        AREA_PATH + "forest_642.c", "southwest",
        AREA_PATH + "forest_643.c", "south",
        AREA_PATH + "forest_644.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 593 ) );
}

