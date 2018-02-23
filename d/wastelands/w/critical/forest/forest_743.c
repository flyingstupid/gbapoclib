/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(743) );
    set_long( get_long_by_id(743) );


    set_exits(({
        AREA_PATH + "forest_692.c", "northwest",
        AREA_PATH + "forest_693.c", "north",
        AREA_PATH + "forest_694.c", "northeast",
        AREA_PATH + "forest_742.c", "west",
        AREA_PATH + "forest_744.c", "east",
        AREA_PATH + "forest_792.c", "southwest",
        AREA_PATH + "forest_793.c", "south",
        AREA_PATH + "forest_794.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 743 ) );
}

