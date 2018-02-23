#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The cobblestone road narrows to squeeze between the swamp to the south, and\n"+
      "the steep cliffs to the north. Large trees grow along the edge of the \n"+
      "swamp, thick vines criss crossing from one branch to the next. At the base\n"+
      "of the cliffs, instead of waves crashing on rocks, there is a little cove.\n"+
      "Waves roll onto the sandy beach of the cove below.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for60", "east",
      FOREST_ROOMS+"for58", "west"
    }));
    set_items(({
    }));
}
