#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "The intersection of West Road and Slate Road");
    set_long(
      "You have found your way to the intersection of West Road\n"+
      "and Slate Road. You can see a small church while looking\n"+
      "towards Slate Road. To the west the city wall stands tall.\n"+
      "There is a lamp post here with a small lamp hanging from\n"+
      "it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "intersection",
        "Just look around you, you're standing at it.",
      "West Road",
        "West Road continues to the north and south east.",
      "Slate Road",
        "Slate Road veers off of West Road heading north east.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "street sign",
        "The street sign says:\n"
        "Northeast: Slate Road\n"
        "Southeast: West Road\n"
        "North: West Road\n",
      "sign",
        "The street sign says:\n"
        "Northeast: Slate Road\n"
        "Southeast: West Road\n"
        "North: West Road\n",
      "church",
        "You aren't to close enough to get a better look.",
      "city wall#wall",
        "The city wall is standing to the west.",
    }));
    set_sign_message(
      "The street sign says:\n"
      "Northeast: Slate Road\n"
      "Southeast: West Road\n"
      "North: West Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/west2.c", "southeast",
      "/d/coronos/w/vorax/west4.c", "north",
      "/d/coronos/w/vorax/slate1.c", "northeast",
    }));
  }
      
