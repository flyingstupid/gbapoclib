#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "From the south and west the stagnant swamp fills the air with its foulness.\n"+
      "Maple and pine trees stand along the coast of the island. Their boughs shift\n"+
      "lazily on the breeze, creaking as the leaves rustle on the sea breeze. A \n"+
      "dirt path follows the curves of the land. A loud roaring sound eminates\n"+
      "from the southeast.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for75", "north",
      FOREST_ROOMS+"for64", "east"
    }));
    set_items(({
    }));
}
