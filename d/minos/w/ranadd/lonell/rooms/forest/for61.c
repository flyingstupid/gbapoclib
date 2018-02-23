#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A stand of maple trees extends north and east. It butts against the swamp,\n"+
      "which lays to the south. To the west, a trench has been cut into the earth,\n"+
      "forming a barrier between forest and swamp. The ditch continues for several\n"+
      "meters, straight and deep.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for72", "north",
      FOREST_ROOMS+"for62", "east"
    }));
    set_items(({
    }));
}
