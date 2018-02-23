/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(624) );
    set_long( get_long_by_id(624) );


    set_exits(({
        AREA_PATH + "forest_573.c", "northwest",
        AREA_PATH + "forest_574.c", "north",
        AREA_PATH + "forest_575.c", "northeast",
        AREA_PATH + "forest_623.c", "west",
        AREA_PATH + "forest_625.c", "east",
        AREA_PATH + "forest_673.c", "southwest",
        AREA_PATH + "forest_674.c", "south",
        AREA_PATH + "forest_675.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 624 ) );
}

