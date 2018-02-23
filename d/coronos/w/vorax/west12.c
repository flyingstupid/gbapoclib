#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "The intersection of Wall Street and Residential Road");
    set_long(
      "You are at the intersection of Wall Street and Residential\n"+
      "Road. As you look south you can see a few houses lining the\n"+
      "road. There is a lamp post here with a small lamp hanging\n"+
      "from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "intersection",
        "Just look around you, you're standing at it.",
      "Wall Street.",
        "Wall Street continues east and west.",
      "Residential Road",
        "Residential Road veers off to the south.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "street sign",
        "The street sign says:\n"
        "West: The intersection of Wall Street and Slate Road\n"
        "East: Wall Street\n"
        "South: Residential Road\n",
      "sign",
        "The street sign says:\n"
        "West: The intersection of Wall Street and Slate Road\n"
        "East: Wall Street\n"
        "South: Residential Road\n",
      "houses",
        "The houses are to the south on Residential Road.",
    }));
    set_sign_message(
      "The street sign says:\n"
      "West: The intersection of Wall Street and Slate Road\n"
      "East: Wall Street\n"
      "South: Residential Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/west13.c", "east",
      "/d/coronos/w/vorax/west11.c", "west",
      "/d/coronos/w/vorax/res6.c", "south",
    }));
  }
  
          
