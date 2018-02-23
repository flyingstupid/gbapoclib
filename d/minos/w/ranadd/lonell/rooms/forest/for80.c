#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Flat, grey stones form a circular patio, and have weathered the test of\n"+
      "time. At the center of the patio, a statue stands upon a low pedestal. \n"+
      "A layer of brown leaves lays on the forest floor, rustling with each \n"+
      "passing footstep, however they seem to not fall upon the statue or its\n"+
      "patio. Old and young maples alike stretch their branches high to form a\n"+
      "living dome over the statue.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for87", "north",
      FOREST_ROOMS+"for81", "east",
      FOREST_ROOMS+"for72", "south",
      FOREST_ROOMS+"for79", "west"
    }));
    set_items(({
    }));
}
