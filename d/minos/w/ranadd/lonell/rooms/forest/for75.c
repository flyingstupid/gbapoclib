#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The coastline snakes in an 'S' shape along the northwestern side of the \n"+
      "island. Cliffs lay to the east, while to the west the stagnant swamp \n"+
      "polutes the air with its foul stench. Maple and pine trees stand proud \n"+
      "along the coast of the island, their massive roots crawling across the \n"+
      "ground, digging in whereever possible. A dirt path follows the curves of\n"+
      "the land.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for85", "north",
      FOREST_ROOMS+"for63", "south"
    }));
    set_items(({
    }));
}
