#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "West Road");
    set_long(
      "You are standing on a stretch West Road. To the east you can\n"+
      "see a church off in the distance and to the west is a small,\n"+
      "cobblestone path that leads up to the top of a small hill.  A\n"+
      "large mansion stands atop the hill.  A lamp post stands here,\n"+
      "lighting the streets when night falls.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "West Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "church",
        "The church sticks out from all the other buildings.",
      "horizon",
        "The church is resting upon the horizon.",
      "city wall#wall",
        "The city wall has many vines and cracks running up and down\n"
        "on it.",
    "hill",
      "The small hill has a small path leading up to the mansion at the top.\n",
    "mansion",
      "Though it is far away, it is obvious that the mansion is quite large.\n",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west3.c", "south",
      "/d/coronos/w/vorax/west5.c", "north",
     "d/coronos/w/nightbringer/manor/path_1",  "west",
    }));
  }
  
