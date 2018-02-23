#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A faint path leads from the west to a fresh water pool. Tracks of many\n"+
      "woodland creatures pock the soft ground. The watering hole is fed from\n"+
      "a deep underground source. The center of the pool is a dark blue color,\n"+
      "indicating the depth of the pond. Soft brown-topped cattails line the \n"+
      "edge of the pool. There is no breeze to stir their heads.\n"+ 
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for40", "west"
    }));
    set_items(({
      "path#footpath",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "grass#grasses#reeds",
        "Tall reeds and grasses surround the pool, their heads stand motionless.\n",
      "pond#pool",
        "A small path leads to a fresh water pond, which is surrounded by grasses\n"+
        "and reeds. Many paw prints cover the area.\n",
    }));
}
