#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The northern woods of Lonell consist mainly of maple trees, with a few oaks\n"+
      "still to be found. No road passes through the grove, yet the trees grow \n"+
      "wide enough apart to permit travel. The undergrowth is scarce, however it \n"+
      "is pleasantly accented by purple and yellow wild flowers growing at the \n"+
      "bases of several trees. The grade of the ground rises to the north as it \n"+
      "approaches the nearby cliffs. A ditch has been cut into the earth to the\n"+
      "south, forming a barrior to the marshy swamp.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for78", "north",
      FOREST_ROOMS+"for69", "east",
      FOREST_ROOMS+"for67", "west"
    }));
    set_items(({
    }));
}
