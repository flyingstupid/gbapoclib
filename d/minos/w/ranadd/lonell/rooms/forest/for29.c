#include <mudlib.h>
#include "/include/creators/ranadd.h"
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Mighty oaks give way to soft grasses in this small glen. Although the\n"+
      "swamp threatens to encroache upon this glen, the tranquility of the place\n"+
      "holds strong. Many paw marks of various types and sizes, cover the ground,\n"+
      "leading north and east. A gigantic sycamore can be seen a short way off to\n"+
      "the south.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for34", "north",
      FOREST_ROOMS+"for30", "east",
      FOREST_ROOMS+"for23", "south"
    }));
    set_items(({
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "grass#grasses",
        "Tall grasses sway in the breeze as gentle as waves on an ocean.\n",
      "glen",
        "A peaceful little glen is surrounded by the encroaching swamp. It is a \n"+
        "haven for many wild animals, as a source of fresh water.\n",
      "sycamore#giant sycamore",
        "A lone sycamore tree stands, spreading its branches, providing shade\n"+
        "for the cross roads to the south.\n",
    }));
}
