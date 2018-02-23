/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(641) );
    set_long( get_long_by_id(641) );


    set_exits(({
        AREA_PATH + "forest_590.c", "northwest",
        AREA_PATH + "forest_591.c", "north",
        AREA_PATH + "forest_592.c", "northeast",
        AREA_PATH + "forest_640.c", "west",
        AREA_PATH + "forest_642.c", "east",
        AREA_PATH + "forest_690.c", "southwest",
        AREA_PATH + "forest_691.c", "south",
        AREA_PATH + "forest_692.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 641 ) );
}

