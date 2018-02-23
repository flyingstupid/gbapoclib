/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(683) );
    set_long( get_long_by_id(683) );


    set_exits(({
        AREA_PATH + "forest_632.c", "northwest",
        AREA_PATH + "forest_633.c", "north",
        AREA_PATH + "forest_634.c", "northeast",
        AREA_PATH + "forest_682.c", "west",
        AREA_PATH + "forest_684.c", "east",
        AREA_PATH + "forest_732.c", "southwest",
        AREA_PATH + "forest_733.c", "south",
        AREA_PATH + "forest_734.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 683 ) );
}

