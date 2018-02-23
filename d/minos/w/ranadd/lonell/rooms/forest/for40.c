#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Ancient oak trees line the cobblestone road that follows the western\n"+
      "cliffs of the island. A strong breeze stirs the branches of the giant \n"+
      "oaks, rustling the leaves musically. The broken road turns east a short\n"+
      "way off to the south, and continues northward for some distance in the\n"+
      "opposite direction. A faint path leads east into the swamp.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for46", "north",
      FOREST_ROOMS+"for41", "east",
      FOREST_ROOMS+"for33", "south"
    }));
    set_items(({
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "road",
        "A road passes through the forest, mostly covered by leaves and branches.\n",
      "branches",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "path#footpath",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
    }));
}
