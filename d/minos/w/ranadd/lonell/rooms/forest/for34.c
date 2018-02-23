#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Tall reeds and grasses grow over three feet high. A faint breeze floats\n"+
      "across hollow topped reeds, playing a soft tune for the fuzzy topped\n"+
      "caterwillows to dance to. The swamp seeps up to the very edge of the\n"+
      "swaying grasses, but stops short of maring the beauty of the small glen.\n"+
      "Far to the south, a giant sycamore sends its branches high into the sky.\n"+
      "The tracks of many animals cover the soft ground.\n"+

      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for29", "south"
    }));
    set_items(({
      "grass#grasses#reeds",
        "Tall reeds and grasses sway in the breeze as gentle as waves on an ocean.\n"+
        "They fill the glen with their bobbing heads.\n",
      "glen",
        "A peaceful little glen is surrounded by the encroaching swamp. It is a \n"+
        "haven for many wild animals, as a source of fresh water.\n",
      "sycamore#giant sycamore",
        "A lone sycamore tree stands, spreading its branches, providing shade\n"+
        "for the cross roads to the south.\n",
      "oak#oak tree",
        "A single oak tree grows along the south side of the glen, droppng its\n"+
        "acorns in the glen.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "branches",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
      "tracks#animal tracks",
        "The paw prints of several wild animals have been left in the soft soil.\n",
    }));
}
