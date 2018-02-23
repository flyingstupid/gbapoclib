#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Slate Road");
    set_long(
      "You are standing on a stretch of Slate Road. To the north\n"+
      "you can barely see a large stone wall peeking up above the\n"+
      "horizon. There is a small church with very detailed stained\n"+
      "glass windows. There is a lamp post here with a small lamp\n"+
      "hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "Slate Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "stone wall#wall",
        "The wall is just barely peeking over the horizon.",
      "small church#church",
        "The church is very small yet beautiful.",
      "stained glass windows#windows",
        "These stained glass windows are very detailed.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/slate1.c", "southwest",
      "/d/coronos/w/vorax/slate3.c", "northeast",
      "/d/coronos/w/vorax/church1.c", "east",    
    }));
  }
  
      
      
    
