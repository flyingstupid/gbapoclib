/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(880) );
    set_long( get_long_by_id(880) );


    set_exits(({
        AREA_PATH + "forest_829.c", "northwest",
        AREA_PATH + "forest_830.c", "north",
        AREA_PATH + "forest_831.c", "northeast",
        AREA_PATH + "forest_879.c", "west",
        AREA_PATH + "forest_881.c", "east",
        AREA_PATH + "forest_929.c", "southwest",
        AREA_PATH + "forest_930.c", "south",
        AREA_PATH + "forest_931.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 880 ) );
}

