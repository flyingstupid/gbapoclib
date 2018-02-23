#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "A stretch of Residential Road");
    set_long(
      "The air is poisoned with the smell of dust. It seems to be\n"+
      "coming from the south. The roof of a small home to the west\n"+
      "reflects the light of the sun directly into your eyes.\n"+
      "There is a lamp post here with a small lamp hanging from it\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The sun is very bright and warm.\n");
    set_day_items
    (({
      "sun",
        "You can't look at it.",
    }));
    set_night_desc(
      "There is a full moon in the night sky.\n");
    set_night_items
    (({
      "full moon#moon",
        "It is very large",
    }));
    set_items
    (({
      "Residential Road",
        "Just look around you, you're standing on it.",
      "intersection",
        "The intersection is to the south of you.",
      "dirt path",
        "The dirt path is to the south.",
      "West Road",
        "West Road is far to the north.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",     }));
      "dust",
        "It's just plain and ordinary dust.",
      "roof",
        "You can't look directly at it.",
    set_exits
    (({
      "/d/coronos/w/vorax/res4.c", "south",
      "/d/coronos/w/vorax/res6.c", "north",
      "/d/coronos/w/vorax/h2r1.c", "west",
    }));
  } 

