#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Residential Road");
    set_long(
      "You are standing on a stretch of Residential Road. There\n"+
      "is a lot of dust blowing around in the air, it is coming\n"+
      "from a path running across the road to the north. There\n"+
      "is a lamp post here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The sun beats down on you from above.\n");
    set_day_items
    (({
      "sun",
        "The sun is too bright, forcing you to look away.",
    }));
    set_night_desc(
      "The moon is shining, casting shadows on the road.\n");
    set_night_items
    (({
      "moon",
        "The moon is big and far into the sky.",
      "shadows",
        "The shadows are thrown across the road.",
      "road",
        "The road is blue from the moon's glow.",
    }));
    set_items
    (({
      "Residential Road#road",
        "Just look around you, it's what you're travelling on.",
      "path#dirt path",
        "This is a dirt path crossing the road to the north.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
       "dirt",
        "The dirt is blowing around all over the place.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/res2.c", "south",       "/d/coronos/w/vorax/res4.c", "north",
    }));
  } 

