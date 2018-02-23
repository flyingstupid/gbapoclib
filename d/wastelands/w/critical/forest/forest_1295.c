/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1295) );
    set_long( get_long_by_id(1295) );


    set_exits(({
        AREA_PATH + "forest_1244.c", "northwest",
        AREA_PATH + "forest_1245.c", "north",
        AREA_PATH + "forest_1246.c", "northeast",
        AREA_PATH + "forest_1294.c", "west",
        AREA_PATH + "forest_1296.c", "east",
        AREA_PATH + "forest_1344.c", "southwest",
        AREA_PATH + "forest_1345.c", "south",
        AREA_PATH + "forest_1346.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1295 ) );
}

