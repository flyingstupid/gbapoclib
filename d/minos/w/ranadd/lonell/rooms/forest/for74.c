#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A trail passes through the woods, leading west and north. It is nearly \n"+
      "invisible, covered over by the dead leaves from many seasons. Frail \n"+
      "looking wild flowers cluster around the roots of many maples, whose shed \n"+
      "foliage lays thick on the ground. A soft breeze dances through branches \n"+
      "high overhead, rustling them musically. An unbelievable stench eminates\n"+
      "from the swamp to the south and east.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for82", "north",
      FOREST_ROOMS+"for73", "west"
    }));
    set_items(({
    }));
}
