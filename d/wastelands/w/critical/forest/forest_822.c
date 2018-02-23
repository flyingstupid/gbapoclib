/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(822) );
    set_long( get_long_by_id(822) );


    set_exits(({
        AREA_PATH + "forest_771.c", "northwest",
        AREA_PATH + "forest_772.c", "north",
        AREA_PATH + "forest_773.c", "northeast",
        AREA_PATH + "forest_821.c", "west",
        AREA_PATH + "forest_823.c", "east",
        AREA_PATH + "forest_871.c", "southwest",
        AREA_PATH + "forest_872.c", "south",
        AREA_PATH + "forest_873.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 822 ) );
}

