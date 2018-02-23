#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A deep ditch has been cut into the earth to the south, following the \n"+
      "forest westward. The branches of the maples that grow along the northern \n"+
      "shores stand motionless. A faint trail passes through the woods. Very \n"+
      "little shrubbery grows amidst the maple trees, however several delicate\n"+
      "purple and yellow wild flowers grow at the base of many trees.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for79", "north",
      FOREST_ROOMS+"for72", "east",
      FOREST_ROOMS+"for70", "west"
    }));
    set_items(({
    }));
}
