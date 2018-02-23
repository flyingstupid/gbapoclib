#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old, worn-out cobblestone road leads east and west. Lining the road on\n"+
      "either side, great oaks stand tall and stately, spreading their thick\n"+
      "boughs ever skyward. A brisk breeze carries the sea air with it, rustling\n"+
      "branches and fallen leaves alike.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for28", "east",
      FOREST_ROOMS+"for26", "west"
    }));
    set_items(({
      "road",
        "A road passes through the forest, mostly covered by leaves and branches.\n",
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "bough#boughs",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
    }));
}
