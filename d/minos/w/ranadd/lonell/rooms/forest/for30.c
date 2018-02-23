#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Tall grasses and reeds grow nearly three feet tall. The faint breeze\n"+
      "makes the puffy tops of caterwillows dance to the whistling of hollow\n"+
      "topped reeds. A solitary oak rises to the south along the invisible\n"+ 
      "boundary between the glen and the swamp. East and north, the grasses\n"+
      "of the glen stop abruptly, as the ground suddenly turns soft and mushy.\n"+

      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for29", "west"
    }));
    set_items(({
      "oak#oak tree",
        "A single oak tree grows along the south side of the glen, droppng its\n"+
        "acorns in the glen.\n",
      "grass#grasses#reeds",
        "Tall reeds and grasses sway in the breeze as gentle as waves on an ocean.\n"+
        "They fill the glen with their bobbing heads.\n",
      "glen",
        "A peaceful little glen is surrounded by the encroaching swamp. It is a \n"+
        "haven for many wild animals, as a source of fresh water.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
    }));
}
