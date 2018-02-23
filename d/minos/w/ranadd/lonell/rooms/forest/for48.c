#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A relatively narrow, yet swift river butts a stand of oaks and pines. The\n"+
      "forest floor is covered with fallen twigs and leaves. On the far side of\n"+
      "the river, a path leads through the swamp. The river flows to the east,\n"+
      "where it widens before becoming a powerful waterfall. Along the near side\n"+
      "of the river, a well worn trail follows the river's edge.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for49", "east",
      FOREST_ROOMS+"for47", "west"
    }));
    set_items(({
    }));
}
