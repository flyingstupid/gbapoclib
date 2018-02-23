#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Southern West Road");
    set_long(
      "You have wandered onto a stretch of West Road. A very big\n"+
      "stone wall is towering over you from the west. There is\n"+
      "a little bit of dust in the air. There is a lamp post here\n"+
      "with a small lamp hanging on it.\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The stone wall blocks out part of the sun.\n");
    set_day_items
    (({
      "sun",
        "It's still too bright to look at.",
    }));
    set_night_desc(
      "The moon casts strange shadows off the wall.\n");
    set_night_items
    (({
      "moon",
        "The moon is high and full in the night sky.",
      "shadows",
        "The shadows are long and strange.",
    }));
    set_items
    (({
      "West Road",
        "Just look around you, you're standing on it.",
      "Main Street",
        "You can see Main Street to your east.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here, lighting the streets.",
      "stone wall#wall",
        "The stone wall has many cracks in it with vines climbing\n"
        "to the top.",
      "dust",
        "The dust is coming from the east.",
    }));
    set_exits
    (({
      "d/coronos/w/vorax/street1.c", "south",
      "/d/coronos/w/vorax/main2.c", "east",
      "/d/coronos/w/vorax/west2.c", "northwest",
    }));
  }
  
  
       
