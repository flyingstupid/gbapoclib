#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "A very large bedroom");
    set_long(
      "This is a very big room with three beds around the walls\n"+
      "of the room.  It looks as if the family who lives here\n"+
      "is gone, as they are no where in the house.  The family\n"+
      "must have spent all of the money on the other parts of\n"+
      "the house, so they all have to sleep in one room.\n");
    set_weather(1, 2, 0);
    set_items
    (({
      "bed#beds",
        "These three beds are not very big as they all have to fit\n"+
        "in one room.\n",
    }));
    set_exits
    (({       "/d/coronos/w/vorax/h2r2.c", "south",
    }));
  } 

