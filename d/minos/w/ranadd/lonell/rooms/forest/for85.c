#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Gigantic maple trees stand proud on the northeastern corner of the \n"+
      "island. Their massive roots sprawl across the ground, digging in where\n"+
      "ever possible. The sheer number of roots that grow along this section of\n"+
      "coast helps to prevent erosion of the land. A dirt path rounds the corner\n"+
      "and dips down several feet with the level of the land.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for75", "south",
      FOREST_ROOMS+"for84", "west"
    }));
    set_items(({
    }));
}
