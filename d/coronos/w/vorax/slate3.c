#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Slate Road");
    set_long(
      "You are walking on a stretch of Slate Road. There is a very\n"+
      "large stone wall towering over you to the northeast. There\n"+
      "is a lamp post here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_night_desc(
      "The wall creates many shadows along the street.\n");
    set_night_items
    (({
      "shadows",
        "These shadows were thrown across the street by the wall.",
    }));
    set_items
    (({
      "Slate Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "stone wall#wall",
        "The stone wall must be at least 15 feet high with cracks\n"
        "and vines hanging from it.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/slate2.c", "southwest",
      "/d/coronos/w/vorax/west11.c", "northeast",
    }));
  }
  
      
      
