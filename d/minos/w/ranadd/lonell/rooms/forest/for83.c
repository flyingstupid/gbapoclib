#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A dirt path slinks its way between the northern cliffs and the swamp\n"+
      "that envelopes the center of the island. The pathway is covered with\n"+
      "fallen leaves that are stirred by a soft breeze that flutters across it.\n"+
      "The tangy sweet smell of the salty sea air against the stench emanating \n"+
      "from the swamp clash like titans at war.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for84", "east",
      FOREST_ROOMS+"for82", "west"
    }));
    set_items(({
    }));
}
