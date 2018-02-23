#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A trail passes through the woods, leading east and south. It is covered \n"+
      "by the fallen leaves from many seasons. Clustered around the roots of \n"+
      "many maples, whose shed foliage lays thick on the ground, purple and \n"+
      "yellow wild flowers add a bright accent to the browns and greens of the\n"+
      "copse. A soft breeze flutters through branches high overhead, rustling \n"+
      "them musically.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for83", "east",
      FOREST_ROOMS+"for74", "south",
      FOREST_ROOMS+"for81", "west"
    }));
    set_items(({
    }));
}
