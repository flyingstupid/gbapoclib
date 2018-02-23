/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(97) );
    set_long( get_long_by_id(97) );


    set_exits(({
        AREA_PATH + "forest_46.c", "northwest",
        AREA_PATH + "forest_47.c", "north",
        AREA_PATH + "forest_48.c", "northeast",
        AREA_PATH + "forest_96.c", "west",
        AREA_PATH + "forest_98.c", "east",
        AREA_PATH + "forest_146.c", "southwest",
        AREA_PATH + "forest_147.c", "south",
        AREA_PATH + "forest_148.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 97 ) );
}

