#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if (!present("corpse"))
        move_object(clone_object(CASTLE_ITEMS+"corpse"), this_object());
  if (!present("skeleton"))
        move_object(clone_object(CASTLE_ITEMS+"skeleton"), this_object());

  if(!arg) {
      set_short("Eastern Corridor");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"The bright glitter and glow of gold has been completely drained from this\n"+
"room. It looks as though someone has sucked the life right out of the\n"+
"entire room!! The walls are scorched, all the portraits have been burnt to\n"+
"ashes, the chandeliers have been destroyed and all the tiles are gone!\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
      set_exits(({
        CASTLE_ROOMS+"out9",  "north",
       CASTLE_ROOMS+"out11",  "south",
      }));
      set_weather(2,2,0);
  }
}
