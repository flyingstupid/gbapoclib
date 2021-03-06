/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit "wiz/kate/open/city.c";

#include "autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( get_short_by_id(7) );
    set_long( get_long_by_id(7) );


    set_exits(({
        AREA_PATH + "blankcity_3.c", "northwest",
        AREA_PATH + "blankcity_4.c", "north",
        AREA_PATH + "blankcity_5.c", "northeast",
        AREA_PATH + "blankcity_6.c", "west",
        AREA_PATH + "blankcity_8.c", "east",
    }));

    set_room_type("city");
}

