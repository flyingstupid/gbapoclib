/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(921) );
    set_long( get_long_by_id(921) );


    set_exits(({
        AREA_PATH + "forest_870.c", "northwest",
        AREA_PATH + "forest_871.c", "north",
        AREA_PATH + "forest_872.c", "northeast",
        AREA_PATH + "forest_920.c", "west",
        AREA_PATH + "forest_922.c", "east",
        AREA_PATH + "forest_970.c", "southwest",
        AREA_PATH + "forest_971.c", "south",
        AREA_PATH + "forest_972.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 921 ) );
}

