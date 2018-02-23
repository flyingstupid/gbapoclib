#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "West Road");
    set_long(
      "You are standing on a stretch of West Road. Up ahead to the\n"+
      "north the road makes a turn to the east. The city wall is\n"+
      "beside you. There is a lamp post here with a small lamp\n"+
      "hanging from it.\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The city wall blocks out some of the sun.\n");
    set_day_items
    (({
      "sun",
        "You can see only half of the golden ball.",
    }));
    set_items
    (({
      "West Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "road",
        "Just look around you, you're standing on it.",
      "city wall#wall",
        "The city wall has many cracks and vines on and around it.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west7.c", "north",
      "/d/coronos/w/vorax/west5.c", "south",
    }));
  }
  
