#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "The intersection of Main Street and a dirt alley");
    set_long(
      "You have found your way to the intersection of Main Street\n"+
      "and a dirt alley. There is a lot of dirt flying around in\n"+
      "the air. To the west you can see a large stone wall. There\n"+
      "is a lamp post here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_day_desc(
      "The sun reflects off the dirt.\n");
    set_night_desc(
      "The stone wall creates a long shadow across the road.\n");
    set_night_items
    (({
      "long shadow#shadow",
        "It's just a normal shadow.",
    }));
    set_items
    (({
      "intersection",
        "Just look around you, you're standing in it.",
      "Main Street",
        "Just look around you, you're standing on it.",
      "dirt alley",
        "This is a small dirt alley leading away to the north.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "street sign",
        "The street sign says:\n"
        "North:  A small dirt alley\n"
        "West:  West Road\n",
      "sign",
        "The street sign says:\n"
        "North:  A small dirt alley\n"
        "West:  West Road\n",
      "dust",
        "This is just plain old dust.",
      "stone wall#wall",
        "The stone wall is very tall, with many cracks running up\n"
        "and down the sides. There are many vines climbing up the\n"
        "wall also.",
    }));
    set_sign_message(
      "The street sign says:\n"
      "North: A small dirt alley\n"
      "West: West Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/main1.c", "east",
      "/d/coronos/w/vorax/alley1.c", "north",
      "/d/coronos/w/vorax/west1.c", "west",
    }));
  }
  
