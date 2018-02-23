/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(757) );
    set_long( get_long_by_id(757) );


    set_exits(({
        AREA_PATH + "forest_706.c", "northwest",
        AREA_PATH + "forest_707.c", "north",
        AREA_PATH + "forest_708.c", "northeast",
        AREA_PATH + "forest_756.c", "west",
        AREA_PATH + "forest_758.c", "east",
        AREA_PATH + "forest_806.c", "southwest",
        AREA_PATH + "forest_807.c", "south",
        AREA_PATH + "forest_808.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 757 ) );
}

