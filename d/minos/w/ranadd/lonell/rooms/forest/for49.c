#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The oaks and pines of this dense grove have litered the forest floor with \n"+
      "fallen sticks and leaves. High cliffs, that seperate the land from the \n"+
      "sea far below stop suddenly as they are drowned out by a great waterfall. \n"+
      "This is obviously the source of the roaring sound. It is very loud, nearly\n"+
      "deafening. The water falls off the side of the island and onto rocks below,\n"+
      "churning the ocean. On the far side of the falls, a path leads into the\n"+
      "swamp.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for45", "south",
      FOREST_ROOMS+"for48", "west"
    }));
    set_items(({
    }));
}
