#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "The intersection of Residential Road and a dirt path");
    set_long(
      "You are at the intersection of Residential Road and a dirt\n"+
      "path. The air is littered with particles of dust. The smell\n"+
      "of the city gardens to the east. There is a lamp post here\n"+
      "with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "It is very hot here.\n");
    set_night_desc(
      "The moon is here glimmering off the dust.\n");
    set_night_items
    (({
      "moon",
        "The moon shines off the dust.",
    }));
    set_items
    (({       "Residential Road",
        "Residential Road leads to the north and south.",
      "dirt path",
        "This is a dirt path that leads to the east and west.",
      "intersection",
        "Just look around you, you're standing in it.",
      "lamp post",
        "This is a lamp post with a lamp hanging on it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "street sign#sign",
        "The street sign says:\n"
        "West:  A small dirt alley\n"
        "East:  A small dirt alley\n"
        "North:  Residential Road\n"
        "South:  Residential Road\n",        
      "dust",
        "This is plain old dust.",
    }));
    set_sign_message(
      "The street sign says:\n"
      "West: A small dirt alley\n"
      "East: A small dirt alley\n"
      "North: Residential Road\n"
      "South: Residential Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/res3.c", "south",
      "/d/coronos/w/vorax/res5.c", "north",
      "/d/coronos/w/vorax/alley5.c", "east",
      "/d/coronos/w/vorax/alley4.c", "west",
    }));
  } 

