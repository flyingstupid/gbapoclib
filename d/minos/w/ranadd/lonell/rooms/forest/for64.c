#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The land yeilds to the cliffs that lay to the east and north, which in \n"+
      "their turn yeild to the great sea. Far below, at the foot of the cliffs,\n"+
      "white crested waves froth as they beat against the rock wall. Maple and \n"+
      "pine trees rise tall and proud along the edgge of the shore. A dirt path\n"+
      "bends west and south with the lay of the land. From the south, there is \n"+
      "an unidentifiable roar.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for56", "south",
      FOREST_ROOMS+"for63", "west"
    }));
    set_items(({
    }));
}
