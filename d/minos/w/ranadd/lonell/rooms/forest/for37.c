#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The wagon trail narrows as it dips down onto the face of the\n"+
      "cliff, avoiding the ever encroaching swamp. It is barely wide\n"+
      "enough to support a horse drawn cart, let alone a trade \n"+
      "wagon. South of the cliffs, white crested waves break on the \n"+
      "vast blue canvas of a sea that seems to extend forever.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for38", "east",
      FOREST_ROOMS+"for36", "west"
    }));
    set_items(({
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "trail#wagon trail#trade route",
        "Once a popular trade route for the island kingdom, the trail is no \n"+
        "longer in use.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "sea",
        "Vast and blue, it stretches to the horizon and beyond.\n",
    }));
}
