#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Age old maple trees populate this woods on the northern shore of Lonell, \n"+
      "although, one ancient oak stands alone, faithfully shedding its acorns to \n"+
      "the ground. To the north and east, the land suddenly drops away. High rocky\n"+
      "cliffs span the distance from the ground to the ocean, some thirty feet \n"+
      "seperated. The coast line extends west and south. The tang of the salty \n"+
      "sea hangs on the air.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for68", "south",
      FOREST_ROOMS+"for77", "west"
    }));
    set_items(({
    }));
}
