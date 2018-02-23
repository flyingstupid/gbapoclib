#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A narrow wagon trail leads up from the side of the cliffs \n"+
      "into a dense copse of trees. At the top of the cliff, the \n"+
      "trail has been devoured by thick undergrowth, leaving only \n"+
      "faint traces of a trade route through the region. Strong \n"+
      "waves on an azure sea beat against the rocky cliffs,all but \n"+
      "drowning out a faint roaring from the northeast.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below masks a loud\n"+
      "roaring from somewhere to the northeast.\n");
    set_exits(({
      FOREST_ROOMS+"for43", "north",
      FOREST_ROOMS+"for39", "east",
      FOREST_ROOMS+"for37", "west"
    }));
    set_items(({
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "trail#wagon trail#trade route",
        "Once a popular trade route for the island kingdom, the trail is no \n"+
        "longer in use.\n",
      "sea",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "copse",
        "A thick cluster of trees.\n",
      "undergrowth#scrub#shrubbery",
        "Ground level plants spread out across the forest floor.\n",
    }));
}
