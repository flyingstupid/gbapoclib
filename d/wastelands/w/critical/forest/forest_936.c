/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(936) );
    set_long( get_long_by_id(936) );


    set_exits(({
        AREA_PATH + "forest_885.c", "northwest",
        AREA_PATH + "forest_886.c", "north",
        AREA_PATH + "forest_887.c", "northeast",
        AREA_PATH + "forest_935.c", "west",
        AREA_PATH + "forest_937.c", "east",
        AREA_PATH + "forest_985.c", "southwest",
        AREA_PATH + "forest_986.c", "south",
        AREA_PATH + "forest_987.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 936 ) );
}
