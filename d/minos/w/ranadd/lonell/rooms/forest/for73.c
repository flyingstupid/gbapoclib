#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A trail passes through the woods, leading east and west. It is obscured\n"+
      "by the dead leaves from many seasons. Delicate purple and yellow wild \n"+
      "flowers also poke through the shed foliage of the maples of the forest. \n"+
      "The flowers cluster around the roots of many of the maples. A soft breeze\n"+
      "dances playfully through branches high overhead.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for81", "north",
      FOREST_ROOMS+"for74", "east",
      FOREST_ROOMS+"for62", "south",
      FOREST_ROOMS+"for72", "west"
    }));
    set_items(({
    }));
}
