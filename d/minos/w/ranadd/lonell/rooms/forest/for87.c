#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Sprouting along the northern most point on the coast of the island, \n"+
      "maple trees crowd together tightly. They seem to occupy most of the \n"+
      "ground, as if trying to cover every square inch of land. High cliffs \n"+
      "fall into a vast blue ocean which stretches seemingly endless, broken \n"+
      "only by the white crests of waves that play upon its surface. Fallen \n"+
      "leaves cover the forest floor. They crunch with each passing footstep. \n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for88", "east",
      FOREST_ROOMS+"for80", "south",
      FOREST_ROOMS+"for86", "west"
    }));
    set_items(({
    }));
}
