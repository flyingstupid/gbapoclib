/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(801) );
    set_long( get_long_by_id(801) );


    set_exits(({
        AREA_PATH + "forest_750.c", "northwest",
        AREA_PATH + "forest_751.c", "north",
        AREA_PATH + "forest_752.c", "northeast",
        AREA_PATH + "forest_800.c", "west",
        AREA_PATH + "forest_802.c", "east",
        AREA_PATH + "forest_850.c", "southwest",
        AREA_PATH + "forest_851.c", "south",
        AREA_PATH + "forest_852.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 801 ) );
}

