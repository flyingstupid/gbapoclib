#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "South West Road");
    set_long(
      "You are standing on a stretch of West Road. The city wall\n"+
      "is towering over you to the west. There is a lamp post here\n"+
      "with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "West Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "city wall#wall",
        "The city wall is large with many cracks and vines on it.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west1.c", "southeast",
      "/d/coronos/w/vorax/west3.c", "northwest",
    }));
  }
  
      
        
