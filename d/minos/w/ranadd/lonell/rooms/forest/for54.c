#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Leading from the north, a simple trail turns east, heading toward the\n"+
      "center of the island. Several maples, oaks and even a few sycamore trees\n"+
      "stretch their branches into a tight web overhead, giving shelter to the \n"+
      "narrow trail, which lays just above the level of the putrid lake of the \n"+
      "swamp.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for60", "north",
      FOREST_ROOMS+"for55", "east"
    }));
    set_items(({
    }));
}
