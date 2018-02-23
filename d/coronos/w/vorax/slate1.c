#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Slate Road");
    set_long(
      "You have found your way to a section of Slate Road. Up to\n"+
      "the northeast you can see a church standing alone amidst\n"+
      "all the other large buildings. There is a lamp post here\n"+
      "with a small lamp hanging on it.\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The sun reflects off the church's stained glass windows.\n");
    set_day_items
    (({
      "sun",
        "You can't look directly at it but you can feel it's heat.",
    }));
    set_night_desc(
      "The moon reflects blue light off the church's stained glass\n"+
      "windows.\n");
    set_night_items
    (({
      "moon",
        "The moon is full and bright.",
    }));
    set_items
    (({
      "Slate Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a lamp post with a lamp hanging on it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "church",
        "The church looks strange among larger buildings.",
      "large buildings#buildings",
        "The large buildings dwarf the church.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west3.c", "southwest",
      "/d/coronos/w/vorax/slate2.c", "northeast",
    }));
  }
  
    
