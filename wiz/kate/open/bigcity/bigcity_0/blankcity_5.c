/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit "wiz/kate/open/city.c";

#include "autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( get_short_by_id(5) );
    set_long( get_long_by_id(5) );


    set_exits(({
        AREA_PATH + "blankcity_1.c", "northwest",
        AREA_PATH + "blankcity_2.c", "north",
        AREA_PATH + "blankcity_4.c", "west",
        AREA_PATH + "blankcity_7.c", "southwest",
        AREA_PATH + "blankcity_8.c", "south",
    }));

    set_room_type("city");
}

