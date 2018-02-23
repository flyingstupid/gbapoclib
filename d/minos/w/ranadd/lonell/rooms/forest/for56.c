#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "High cliffs that surround the whole island meet the land, forcing it to\n"+
      "yeild. Far below, at the foot of the cliffs, white crested waves foam\n"+
      "as they beat at the bottom of the rock face. Several types of trees stand\n"+
      "at the western edge of the island. The dirt path snakes to the west\n"+
      "just north of this point. And to the south, a loud roaring sound seems\n"+
      "very close.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for64", "north",
      FOREST_ROOMS+"for52", "south"
    }));
    set_items(({
    }));
}
