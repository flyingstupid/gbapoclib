#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The maples of the grove crowd together, but not so closely that travel \n"+
      "through the grove is hindered too much. Trees grow in every direction. \n"+
      "To the north and east, the forest yeilds to the cliffs that surround the\n"+
      "island. While westward, the trees span out to form a little clearing. And\n"+
      "to the south and east, a path travels through the woods.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for88", "north",
      FOREST_ROOMS+"for82", "east",
      FOREST_ROOMS+"for73", "south",
      FOREST_ROOMS+"for80", "west"
    }));
    set_items(({
    }));
}
