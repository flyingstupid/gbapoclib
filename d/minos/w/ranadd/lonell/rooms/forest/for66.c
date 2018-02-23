#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The broken remains of a disused cobblestone road leads from the south,\n"+
      "where an old sycamore stands. The trail to the south appears to lead into \n"+
      "the swamp a short way off. Here and to the north, it hugs the coastline. \n"+
      "To the west, a cove lays at the foot of the cliffs that encompass the \n"+
      "entire island. A staircase can be seen on the opposite side if the cove,\n"+
      "leading down the face of the cliffs, but it is broken and could no longer \n"+
      "support the weight of even a child, even if it were all there.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for76", "north",
      FOREST_ROOMS+"for67", "east",
      FOREST_ROOMS+"for60", "south"
    }));
    set_items(({
    }));
}
