/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(780) );
    set_long( get_long_by_id(780) );


    set_exits(({
        AREA_PATH + "forest_729.c", "northwest",
        AREA_PATH + "forest_730.c", "north",
        AREA_PATH + "forest_731.c", "northeast",
        AREA_PATH + "forest_779.c", "west",
        AREA_PATH + "forest_781.c", "east",
        AREA_PATH + "forest_829.c", "southwest",
        AREA_PATH + "forest_830.c", "south",
        AREA_PATH + "forest_831.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 780 ) );
}

