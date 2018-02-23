#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Wall Street");
    set_long(
      "You are standing on a section of Wall Street. You can see\n"+
      "Slate Road with it's churches to the east. The city wall\n"+
      "is lining the north. There is a lamp post here with a small\n"+
      "lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "churches",
        "These churches are along Slate Road.",
      "city wall#wall",
        "The city wall is lined with cracks and vines.",
      "Slate Road",
        "Slate Road is to the east.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west8.c", "west",
      "/d/coronos/w/vorax/west10.c", "east",
    }));
  }
  
