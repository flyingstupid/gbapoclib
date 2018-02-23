/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1742) );
    set_long( get_long_by_id(1742) );


    set_exits(({
        AREA_PATH + "forest_1691.c", "northwest",
        AREA_PATH + "forest_1692.c", "north",
        AREA_PATH + "forest_1693.c", "northeast",
        AREA_PATH + "forest_1741.c", "west",
        AREA_PATH + "forest_1743.c", "east",
        AREA_PATH + "forest_1791.c", "southwest",
        AREA_PATH + "forest_1792.c", "south",
        AREA_PATH + "forest_1793.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1742 ) );
}

