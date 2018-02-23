#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Wall Street");
    set_long(
      "You are at a section of Wall Street. You can smell the\n"+
      "city gardens from here. The city wall is to the north.\n"+
      "There is a lamp post here with a small lamp hanging from it\n");
    set_weather(2, 4, 0);
	set_land_value(300000);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "gardens",
        "The gardens are to the east.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "city wall#wall",
        "The wall is lined with many vines and cracks.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west13.c", "west",
      "/d/coronos/w/vorax/west15.c", "east",
    }));
    }
    
