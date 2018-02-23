/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1615) );
    set_long( get_long_by_id(1615) );


    set_exits(({
        AREA_PATH + "forest_1564.c", "northwest",
        AREA_PATH + "forest_1565.c", "north",
        AREA_PATH + "forest_1566.c", "northeast",
        AREA_PATH + "forest_1614.c", "west",
        AREA_PATH + "forest_1616.c", "east",
        AREA_PATH + "forest_1664.c", "southwest",
        AREA_PATH + "forest_1665.c", "south",
        AREA_PATH + "forest_1666.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1615 ) );
}

