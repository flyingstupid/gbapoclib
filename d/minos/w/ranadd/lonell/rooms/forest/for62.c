#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A stand of maple trees extends north and west, holding tightly to the \n"+
      "solid ground. It butts against the swamp, which lays to the south and \n"+
      "east. Fragile looking flowers spring from the bases of the thick maples\n"+
      "which populate the region. A faint breeze whispers through the closely \n"+
      "woven branches high overhead.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for73", "north",
      FOREST_ROOMS+"for61", "west"
    }));
    set_items(({
    }));
}
