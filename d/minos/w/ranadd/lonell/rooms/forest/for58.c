#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old cobblestone road runs east and west, surrounded by old oaks and an\n"+
      "occasional maple. One young oak grows right out of the center of the road,\n"+
      "its roots pushing aside the few cobblestones that have survived the years\n"+
      "since the road's construction. North of the road, a grassy jetty looks out\n"+
      "onto the sea on the north side of the island.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for65", "north",
      FOREST_ROOMS+"for59", "east",
      FOREST_ROOMS+"for57", "west"
    }));
    set_items(({
    }));
}
