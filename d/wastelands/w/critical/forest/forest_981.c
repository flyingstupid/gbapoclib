/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(981) );
    set_long( get_long_by_id(981) );


    set_exits(({
        AREA_PATH + "forest_930.c", "northwest",
        AREA_PATH + "forest_931.c", "north",
        AREA_PATH + "forest_932.c", "northeast",
        AREA_PATH + "forest_980.c", "west",
        AREA_PATH + "forest_982.c", "east",
        AREA_PATH + "forest_1030.c", "southwest",
        AREA_PATH + "forest_1031.c", "south",
        AREA_PATH + "forest_1032.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 981 ) );
}

