#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The ocean meets the cliffs to the south, pounding them with \n"+
      "great ferocity. The edge of the shore runs away south and \n"+
      "east. An old wagon trail hugs the edge of the cliff closely,\n"+
      "and to the east it even dips down along the face of the \n"+
      "cliffs where the ground became too soft to support the trade\n"+
      "route.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for37", "east",
      FOREST_ROOMS+"for35", "west"
    }));
    set_items(({
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "trail#wagon trail#trade route",
        "Once a popular trade route for the island kingdom, the trail is no \n"+
        "longer in use.\n",
    }));
}
