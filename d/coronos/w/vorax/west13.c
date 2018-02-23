#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Wall Street");
    set_long(
      "You are standing on a stretch of Wall Street. You can see\n"+
      "most of the Residential area of Coronos from here. There\n"+
      "is a lamp post here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
	set_land_value(170000);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "city",
        "It's just too big to take in.",
      "intersection",
        "The intersection is to the west.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp here to light the streets.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west12.c", "west",
      "/d/coronos/w/vorax/west14.c", "east",
    }));
  }
  
