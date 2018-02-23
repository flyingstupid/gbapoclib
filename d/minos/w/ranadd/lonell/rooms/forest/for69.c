#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Sheer cliffs drop into the ocean to the north, while to the south, a ditch\n"+
      "has been cut into the earth, creating a natural barrior to the marshy \n"+
      "swamp. No breeze stirs the branches of the maples and few oaks that grow \n"+
      "along the northern shores, nor does any road pass between the cliffs and \n"+
      "the swamp. Undergrowth is scarce, however it is pleasantly accentuated by \n"+
      "purple and yellow wild flowers growing at the bases of several of the trees.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for70", "east",
      FOREST_ROOMS+"for68", "west"
    }));
    set_items(({
    }));
}
