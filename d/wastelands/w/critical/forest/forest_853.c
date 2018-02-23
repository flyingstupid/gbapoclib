/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(853) );
    set_long( get_long_by_id(853) );


    set_exits(({
        AREA_PATH + "forest_802.c", "northwest",
        AREA_PATH + "forest_803.c", "north",
        AREA_PATH + "forest_804.c", "northeast",
        AREA_PATH + "forest_852.c", "west",
        AREA_PATH + "forest_854.c", "east",
        AREA_PATH + "forest_902.c", "southwest",
        AREA_PATH + "forest_903.c", "south",
        AREA_PATH + "forest_904.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 853 ) );
}

