#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Residential Road");
    set_long(
      "You have found your way to Residential Road. Over to\n"+
      "the east you see a small house, that some of the residents\n"+
      "of Ille Coronos live in. The air is slightly salty.\n"+
      "There is a lamp post here with a small lamp hanging from it\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The sun reflects off the house with great strength.\n");
    set_day_items
    (({
      "sun",
        "You can't get a closer look, it's too bright.",
      "house",
        "The house is reflecting the sun very brightly.",
    }));
    set_night_desc(
      "The moon is full, and gives off some light.\n");
    set_night_items
    (({
      "moon",
        "The moon is full and bright in the sky.",
    }));
    set_items
    (({
      "Residential Road",
        "Just look around you, you're standing in it.",
      "house#small house",
        "This is a small house that a family probably lives in.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
    }));     set_exits
    (({
      "/d/coronos/w/vorax/res1.c", "south",
      "/d/coronos/w/vorax/h1r1.c", "east",
      "/d/coronos/w/vorax/res3.c", "north",
    }));
  } 

