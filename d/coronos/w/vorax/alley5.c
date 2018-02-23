#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "On a dirt path");
    set_long(
      "You have wandered onto a dirt path. You can see the city\n"+
      "gardens, and their wonderful roses to the east. Although\n"+
      "the smell of dirt is strong here the flowers still seep\n"+
      "through. There is a lamp post here with a small lamp\n"+
      "hanging from it.\n");
    set_weather(1, 4, 0);
    set_day_desc(
      "The sun shines down onto you.\n");
    set_items
    (({
      "gardens",
        "These are the city gardens to the east",
      "lamp post",
        "This is a lamp post with a small lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the street light.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/alley6.c", "east",
      "/d/coronos/w/vorax/res4.c", "west",
    }));
  }
  
      
