#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Thich-trunked trees sprout along the shoreline on the northern coast of\n"+
      "this island. High cliffs fall below north and west, to meet the vast blue\n"+
      "ocean which stretches seemingly endless, broken only by the white crests \n"+
      "of waves that play upon its surface. Fallen leaves, brown with decay, \n"+
      "cover the forest floor, rustling loudly with each passing footstep. \n"+
      "Thousands of leagues to the northwest, a speck of land breaks the endless\n"+
      "sea.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for87", "east",
      FOREST_ROOMS+"for79", "south"
    }));
    set_items(({
    }));
}
