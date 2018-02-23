/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit "wiz/kate/open/city.c";

#include "autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( get_short_by_id(6) );
    set_long( get_long_by_id(6) );


    set_exits(({
        AREA_PATH + "blankcity_3.c", "north",
        AREA_PATH + "blankcity_4.c", "northeast",
        AREA_PATH + "blankcity_7.c", "east",
    }));

    set_room_type("city");
}

