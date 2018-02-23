#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "To the south, a deep ditch, running east and west, has been cut into the \n"+
      "earth, creating a natural barrior against the mucky swamp. No breeze floats\n"+
      "in off of the sea to dance among the branches of the maples that grow along\n"+
      "the northern shores, neither does a road pass between the cliffs and the \n"+
      "ditch. Very little shrubbery grows on the northern shore, however delicate\n"+
      "purple and yellow wild flowers grow at the base of several trees.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for71", "east",
      FOREST_ROOMS+"for69", "west"
    }));
    set_items(({
    }));
}
