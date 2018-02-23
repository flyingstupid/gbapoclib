/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(594) );
    set_long( get_long_by_id(594) );


    set_exits(({
        AREA_PATH + "forest_543.c", "northwest",
        AREA_PATH + "forest_544.c", "north",
        AREA_PATH + "forest_545.c", "northeast",
        AREA_PATH + "forest_593.c", "west",
        AREA_PATH + "forest_595.c", "east",
        AREA_PATH + "forest_643.c", "southwest",
        AREA_PATH + "forest_644.c", "south",
        AREA_PATH + "forest_645.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 594 ) );
}

