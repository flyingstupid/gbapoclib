#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old wooden railing skirts the edge of a grassy jetty, which looks out\n"+
      "onto the sea on the north side of the island. To the east, a cove lays\n"+
      "nestled between the high cliffs that surround the island. The timbers of \n"+
      "the railing have rotted from the passage of time and the salt water. A \n"+
      "soft breeze stirs on this look out point. Off in the distance, another \n"+
      "island can be seen. It is many leagues away, and it would be a very long \n"+
      "voyage.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for58", "south"
    }));
    set_items(({
    }));
}
