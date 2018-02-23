#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A stiff breeze carries the tang of salt as it stirs the fallen leaves,\n"+
      "clearing the worn cobblestones of the road that once passed along the\n"+
      "shoreline. The shoreline bends south and west, away from the swamp. Many\n"+
      "tall cypress trees grow in the swamp to the north.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for21", "south",
      FOREST_ROOMS+"for27", "west"
    }));
    set_items(({
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "road",
        "A road passes through the forest, mostly covered by leaves and branches.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "cypress#cypress tree",
        "The tops boughs of the enormous dark cypress sways as a gentle breeze \n"+
        "blows through them. Its roots stick out of the swampy ground, giving it \n"+
        "the look of a living creature with branches that seem long, dark hands \n"+
        "reaching downwards from the sky to grab you and wisk you away into some \n"+
        "dark land of no return.\n",
    }));
}
