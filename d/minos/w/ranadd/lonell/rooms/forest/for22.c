#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Huge oaks crowd together, entwining their branches tightly to create\n"+
      "a ceiling of green. Very little light shines down through the thick\n"+
      "sheltering canopy. Only a few hearty vines are able to flourish along\n"+
      "the lightless ground. The cobblestone path splits, leading south and\n"+
      "west along the coast, and east toward an ancient sycamore.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for23", "east",
      FOREST_ROOMS+"for13", "south",
      FOREST_ROOMS+"for21", "west"
    }));
    set_items(({
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "branches",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "sycamore",
        "A lone sycamore tree stands, spreading its branches, providing shade\n"+
        "on the cross roads.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "vine#vines",
        "A few thorny vines grow along the ground and up the trunks of a few \n"+
        "trees.\n",
    }));
}
