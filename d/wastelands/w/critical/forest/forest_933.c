/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(933) );
    set_long( get_long_by_id(933) );


    set_exits(({
        AREA_PATH + "forest_882.c", "northwest",
        AREA_PATH + "forest_883.c", "north",
        AREA_PATH + "forest_884.c", "northeast",
        AREA_PATH + "forest_932.c", "west",
        AREA_PATH + "forest_934.c", "east",
        AREA_PATH + "forest_982.c", "southwest",
        AREA_PATH + "forest_983.c", "south",
        AREA_PATH + "forest_984.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 933 ) );
}

