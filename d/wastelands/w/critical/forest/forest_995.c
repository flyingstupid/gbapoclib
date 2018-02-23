/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(995) );
    set_long( get_long_by_id(995) );


    set_exits(({
        AREA_PATH + "forest_944.c", "northwest",
        AREA_PATH + "forest_945.c", "north",
        AREA_PATH + "forest_946.c", "northeast",
        AREA_PATH + "forest_994.c", "west",
        AREA_PATH + "forest_996.c", "east",
        AREA_PATH + "forest_1044.c", "southwest",
        AREA_PATH + "forest_1045.c", "south",
        AREA_PATH + "forest_1046.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 995 ) );
}

