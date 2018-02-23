#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Wall Street");
    set_long(
      "You have wandered to a stretch of Wall Street. You can see\n"+
      "the city wall lining the road to the north. There is a lamp\n"+
      "post here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "city wall#wall",
        "The city wall is lining the road.",
      "road",
        "Just look around you, you're standing on it.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west11.c", "east",
      "/d/coronos/w/vorax/west9.c", "west",
    }));
  }
  
  
