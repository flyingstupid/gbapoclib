#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old road travels north and south along the western edge of the island.\n"+
      "Several cobblestones remain to show its passage, most of them broken, all\n"+
      "of them well worn. Tall oak trees have been planted in straight columns\n"+
      "along either side of the road. Their branches have grown together in a \n"+
      "tight web, sheltering the road. A stiff breeze whips through the boughs,\n"+
      "sending loose leaves flying across the road.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for53", "north",
      FOREST_ROOMS+"for46", "south"
    }));
    set_items(({
    }));
}
