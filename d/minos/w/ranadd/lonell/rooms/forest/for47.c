#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A natural spring bubbles up from the ground, creating a relatively narrow,\n"+
      "yet swift river just north of a well worn trail. South, the forest floor\n"+
      "is covered with fallen twigs and leaves. On the far side of the spring, a\n"+
      "path leads through the swamp. The river flows to the east, where it widens,\n"+
      "eventually becoming a powerful waterfall. Along the near side of the spring,\n"+
      "a well worn trail follows the river's edge to the east, and to the northwest\n"+
      "a knoll rises above the swamp.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for48", "east",
      FOREST_ROOMS+"for51", "northwest"
    }));
    set_items(({
      "spring#natural spring#river",
        "An underground river emerges and flows quickly eastward, where it\n"+
        "becomes a powerful waterfall.\n",
      "waterfall",
        "You are not close enough to see the waterfall.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "path#footpath",
        "A path passes through the swamp on the other side of the river.\n",

      "knoll",
        "A small hill rises above the swamp to the northwest.\n",
    }));
}
