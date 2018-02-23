#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A dirt path leads east and west, squeezing between the northern cliffs\n"+
      "and the swamp that engulfs the center of the island. Fallen leaves swirl\n"+
      "across the pathway, whipped in small circles by an increasing breeze \n"+
      "that flutters across it. A short distance to the east, the coastline \n"+
      "turns southward. The tangy sweet smell of the salt water fills the air.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for85", "east",
      FOREST_ROOMS+"for83", "west"
    }));
    set_items(({
    }));
}
