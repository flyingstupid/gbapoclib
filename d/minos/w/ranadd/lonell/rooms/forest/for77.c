#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Maple trees dominate this copse on the northern shore of Lonell, although\n"+
      "a very few ancient oaks still grow, casting their acorns to the ground. To\n"+
      "the north, the land suddenly drops away. High rocky cliffs span the \n"+
      "distance from the ground to the ocean, some thirty feet apart. The coast \n"+
      "line extends east and west. The tang of the salty sea hangs on the air.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for78", "east",
      FOREST_ROOMS+"for67", "south",
      FOREST_ROOMS+"for76", "west"
    }));
    set_items(({
    }));
}
