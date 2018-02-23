#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A stand of trees, mostly maple with a few oaks here and there, grows on \n"+
      "the northern side of the island. No remains of a road can be found, yet \n"+
      "the trees grow far enough apart, and the undergrowth is little enough that\n"+
      "travel is not to encumbered. The grade of the ground rises to the north \n"+
      "as it approaches the nearby cliffs. A ditch has been cut into the earth to\n"+
      "the south, forming a barrior to the marshy swamp.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for77", "north",
      FOREST_ROOMS+"for68", "east",
      FOREST_ROOMS+"for66", "west"
    }));
    set_items(({
    }));
}
