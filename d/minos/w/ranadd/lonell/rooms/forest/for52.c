#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "High cliffs that surround the entire island, stop suddenly as they are\n"+
      "drowned out by a great waterfall. This is obviously the source of the \n"+
      "roaring sound. It is very loud, nearly deafening. The water falls off the \n"+
      "side of the island and onto rocks below, churning the ocean. A marshy trail\n"+
      "disapears into the swamp to the west, following the narrow river. On the \n"+
      "far side of the falls there is a thick stand of pine and oak trees.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for56", "north",
      SWAMP_ROOMS+"swa50", "west"
    }));
    set_items(({
    }));
}
