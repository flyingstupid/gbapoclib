/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(675) );
    set_long( get_long_by_id(675) );


    set_exits(({
        AREA_PATH + "forest_624.c", "northwest",
        AREA_PATH + "forest_625.c", "north",
        AREA_PATH + "forest_626.c", "northeast",
        AREA_PATH + "forest_674.c", "west",
        AREA_PATH + "forest_676.c", "east",
        AREA_PATH + "forest_724.c", "southwest",
        AREA_PATH + "forest_725.c", "south",
        AREA_PATH + "forest_726.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 675 ) );
}

