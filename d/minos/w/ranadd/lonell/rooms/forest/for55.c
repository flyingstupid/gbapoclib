#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Maples, oaks, and sycamores, many ages old, grow in the damp ground \n"+
      "surrounding the simple trail. Most of the trees grow crooked and are \n"+
      "disfigured from the putrid waters of the swamp, their only source of\n"+
      "water. The trail itself is swallowed by the stagnant lake to the east,\n"+
      "thus ending the passage through swamp that once lead to the center of\n"+
      "the island.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for54", "west"
    }));
    set_items(({
    }));
}
