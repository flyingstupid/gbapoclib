#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Glimpses of the vast ocean can be seen peeking between oaks south and\n"+
      "west. Its deep blue majesty broken only by the white crests of waves\n"+
      "rolling across its surface. On the land, fallen leaves are whipped\n"+
      "through the trees that line the old cobblestone road on the stiff ocean\n"+
      "breeze. The broken road follows the shoreline north and east, hugging it\n"+
      "tightly.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for33", "north",
      FOREST_ROOMS+"for27", "east"
    }));
    set_items(({
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
    }));
}
