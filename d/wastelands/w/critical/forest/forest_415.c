/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(415) );
    set_long( get_long_by_id(415) );


    set_exits(({
        AREA_PATH + "forest_364.c", "northwest",
        AREA_PATH + "forest_365.c", "north",
        AREA_PATH + "forest_366.c", "northeast",
        AREA_PATH + "forest_414.c", "west",
        AREA_PATH + "forest_416.c", "east",
        AREA_PATH + "forest_464.c", "southwest",
        AREA_PATH + "forest_465.c", "south",
        AREA_PATH + "forest_466.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 415 ) );
}

