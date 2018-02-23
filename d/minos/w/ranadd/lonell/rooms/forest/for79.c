#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "High cliffs rise up out of the sea below to meet the forest of maples \n"+
      "on the northern shore of the island. The ocean stretches out, seemingly \n"+
      "endless, broken only occasionally by white crested waves. Brown leaves,\n"+
      "the discarded foliage of many years, cover the forest floor, rustling\n"+
      "loudly with each passing footstep.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for86", "north",
      FOREST_ROOMS+"for80", "east",
      FOREST_ROOMS+"for71", "south"
    }));
    set_items(({
    }));
}
