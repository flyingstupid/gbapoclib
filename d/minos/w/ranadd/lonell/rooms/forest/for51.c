#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Rising above the dankness of the swamp, a small knoll offers a look out\n"+
      "onto the surrounding area. East, a natural spring bubbles out of the ground.\n"+
      "The water of the spring surrounds the knoll at its base, forming a moat\n"+
      "on the east and north sides of the small hill. To the south and west, the \n"+
      "knoll drops into the swamp treacherously.\n"+ 
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for47", "southeast"
    }));
    set_items(({
    }));
}
