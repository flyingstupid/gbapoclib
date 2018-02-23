#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old cobblestone road continues north and south along the western edge of\n"+
      "the island. Tall oak trees have been planted in straight columns along \n"+
      "either side of the road, which turns eastward a short distance to the north.\n"+
      "The branches of the trees have grown together, interlocking to form a tight\n"+
      "weave of green and brown. A stiff breeze whips through the boughs, sending\n"+
      "loose leaves and dust flying across the road.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for57", "north",
      FOREST_ROOMS+"for50", "south"
    }));
    set_items(({
    }));
}
