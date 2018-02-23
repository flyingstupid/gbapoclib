#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old cobblestone road turns east and south to follow the western edge of\n"+
      "the island. Along the road to the south, tall oak trees have been planted\n"+
      "in straight columns along either side of the road. Off to the east more \n"+
      "oaks grow, but less orderly than along the roadside to the south. Northward,\n"+
      "beyond the cliff's edge, an azure sea stretches into the distant horizon.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for58", "east",
      FOREST_ROOMS+"for53", "south"
    }));
    set_items(({
    }));
}
