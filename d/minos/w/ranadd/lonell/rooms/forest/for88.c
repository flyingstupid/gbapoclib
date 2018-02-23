#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "High cliffs fall into a vast blue ocean which extends north and east, \n"+
      "unbroken save by the white crests of waves that play upon its surface. \n"+
      "Maple trees of varying sizes crowd together tightly. They seem to occupy \n"+
      "most of the ground, as if trying to cover every square inch of land. The \n"+
      "fallen leaves of many seasons cover the floor of the forest. They crunch \n"+
      "to dust with each passing footstep. \n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for81", "south",
      FOREST_ROOMS+"for87", "west"
    }));
    set_items(({
    }));
}
