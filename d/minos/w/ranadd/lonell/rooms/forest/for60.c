#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The broken remains of a disused cobblestone road leads from the west,\n"+
      "spliting north and south at the base of an old sycamore. The trail to the\n"+
      "south appears to lead into the swamp, while to the north, it continues to\n"+
      "follow the coasline. To the northwest, a cove lays at the foot of the \n"+
      "cliffs that encompass the entire island.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for66", "north",
      FOREST_ROOMS+"for54", "south",
      FOREST_ROOMS+"for59", "west"
    }));
    set_items(({
    }));
}
