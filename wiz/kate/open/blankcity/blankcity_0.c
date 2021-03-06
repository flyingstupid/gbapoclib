/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit "wiz/kate/open/city.c";

#include "autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( get_short_by_id(0) );
    set_long( get_long_by_id(0) );


    set_exits(({
        AREA_PATH + "blankcity_1.c", "east",
        AREA_PATH + "blankcity_3.c", "south",
        AREA_PATH + "blankcity_4.c", "southeast",
    }));

    set_room_type("city");
}

