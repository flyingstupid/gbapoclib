#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "An old road travels north and south along the western edge of the island.\n"+
      "Several cobblestones mark its passage, many of them missing, most of them\n"+
      "broken, all of the ones remaining are well worn. Tall oak trees have been\n"+
      "planted in straight columns along either side of the road. Their branches\n"+
      "weave together overhead creating a protective awning. A stiff ocean breeze\n"+
      "rustles through the boughs.\n"+ 
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for50", "north",
      FOREST_ROOMS+"for40", "south"
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
    }));
}
