/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(367) );
    set_long( get_long_by_id(367) );


    set_exits(({
        AREA_PATH + "forest_316.c", "northwest",
        AREA_PATH + "forest_317.c", "north",
        AREA_PATH + "forest_318.c", "northeast",
        AREA_PATH + "forest_366.c", "west",
        AREA_PATH + "forest_368.c", "east",
        AREA_PATH + "forest_416.c", "southwest",
        AREA_PATH + "forest_417.c", "south",
        AREA_PATH + "forest_418.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 367 ) );
}

