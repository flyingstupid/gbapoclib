#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Wall Street");
    set_long(
      "You are walking along a stretch of Wall Street. You can\n"+
      "barely see the bushes and hedges of the city gardens from\n"+
      "here. There is a lamp post here with a small lamp hanging\n"+
      "from it.\n");
    set_weather(2, 4, 0);
    set_land_value(100000);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "gardens",
        "The city gardens are to the southeast.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "bushes#hedges",
        "The bushes and hedges are in the gardens.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west15.c", "west",
"/d/coronos/w/darkness/wallst0", "east",
    }));
  }
  
