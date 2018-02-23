#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if(!present("citizen"))
      move_object(clone_object("d/coronos/w/angel/city/monst/citizen"),this_object());

    if (arg) return;
    set_short(
      "Wall Street");
    set_long(
      "You are standing at a stretch of Wall Street that is near\n"+
      "the city gardens. The smell from the gardens is great from\n"+
      "here. There is a lamp post here with a small lamp hanging\n"+
      "from it.\n");
    set_weather(2, 4, 0);
    set_land_value(150000);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "gardens",
        "The city gardens are to the east.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west16.c", "east",
      "/d/coronos/w/vorax/west14.c", "west",
    }));
  }
  
