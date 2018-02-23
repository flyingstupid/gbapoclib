#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Only a few oaks grow among the maples of this woods on the northern side \n"+
      "of the island. Acorns lay everywhere on the ground, mixed in with brown\n"+
      "maple leaves. The land drops into steep cliffs to the north and west. A\n"+
      "sandy beached cove lays at the base of the cliffs to the southeast. An old\n"+
      "broken staircase leads down the cliffs on the opposite side of the cove,\n"+
      "however, time and the salty sea air have won the battle to destroy the \n"+
      "majority of the stairs.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for77", "east",
      FOREST_ROOMS+"for66", "south"
    }));
    set_items(({
    }));
}
