/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1788) );
    set_long( get_long_by_id(1788) );


    set_exits(({
        AREA_PATH + "forest_1737.c", "northwest",
        AREA_PATH + "forest_1738.c", "north",
        AREA_PATH + "forest_1739.c", "northeast",
        AREA_PATH + "forest_1787.c", "west",
        AREA_PATH + "forest_1789.c", "east",
        AREA_PATH + "forest_1837.c", "southwest",
        AREA_PATH + "forest_1838.c", "south",
        AREA_PATH + "forest_1839.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1788 ) );
}

