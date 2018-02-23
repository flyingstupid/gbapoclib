#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The faint marks of a long-since-used trail pass through these woods, \n"+
      "leading east and west. Maple trees grow densly in this area of the \n"+
      "forest on the northwestern side of the island. Delicate purple and \n"+
      "yellow wild flowers grow around the bases of many of the maples. A \n"+
      "soft breeze lightly dances thru the branches high overhead.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for80", "north",
      FOREST_ROOMS+"for73", "east",
      FOREST_ROOMS+"for61", "south",
      FOREST_ROOMS+"for71", "west"
    }));
    set_items(({
    }));
}
