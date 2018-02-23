#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if(!arg) {
    set_short("Minotaur Valley");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"\tMinotaur Valley\n"+
"The southern end of the valley is constantly bombarded with sand storms\n"+
"blowing up off the beach. This harsh treatment of the two mountains which\n"+
"form the valley stops further north. At the northern end of the luscious\n"+
"vale, a large castle towers above all else on the island. It is set into\n"+
"the surrounding mountains which is beneficial to the castle's defense. A\n"+
"small moat separates the castle from the rest of the vale, and two great\n"+
"cliffs stretch towards the heavens on either side, making it impossible to\n"+
"go around.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    set_exits(({
      CASTLE_ROOMS+"entrance",  "north",
      ISLAND_ROOMS+"start",  "south",
    }));
    set_weather(1,4,2);
    set_items(({
      "moat",  "The moat has a bridge across it...luckily",
      "castle",  "The magnificent castle standing before you is covered\n"+
                 "in a rich coating of gold. The floors towards the top\n"+
                 "of the castle look slightly damaged",
      "cliffs",  "The cliffs rise into the heavens",
      "mountains", "The mountains help protect the castle from attack",
      "valley",  "The valley is all around you",
    }));
  set_listen("The wind howls through the valley.");
  }
}




