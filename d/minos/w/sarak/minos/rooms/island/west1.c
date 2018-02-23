#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {

  if (arg) return;
  set_short("A dense rainforest");
  set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"After pushing your way through the dense shrubbery, you find yourself\n"+
"deep within the island's thick rainforest. The trees block out most of\n"+
"the sun with only a few golden rays finding their way through the\n"+
"foliage. The path seems to carry on to the north.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_exits(({
    ISLAND_ROOMS+"start",  "east",
    ISLAND_ROOMS+"pub",  "down",
    ISLAND_ROOMS+"west2",  "north",
  }));
  set_weather(1,4,2);
  set_items (({
    "shrubbery#rainforest#trees#foliage",
      "The incredible thickness of the island's foliage is truly remarkable.\n"+
      "It carries on into the rainforest as far as the eye can see.",
    "sun#rays",
      "The sun sparkles through the overhanging trees here and there.",
    "path",
      "The path carries on to the north. A new one will open to the\n"+
      "southwest very soon.",
  }));
}
