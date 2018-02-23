#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "On a dirt path");
    set_long(
      "You are walking along a small dirt path. The smell of the\n"+
      "city gardens is overwhelming here. It is almost begging you\n"+
      "to come in. There is a lamp post here with a small lamp\n"+
      "hanging from it.\n");
    set_weather(1, 4, 0);
    set_items
    (({
      "path",
        "This is a small dirt path.",
      "gardens",
        "The city gardens put off a wonderful smell from the east."
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/alley5.c", "west",
"/d/coronos/w/angel/city/gardens/garden5", "east",
    }));
  }
  
