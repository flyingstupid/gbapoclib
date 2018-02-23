#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
  if(!present("rat")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/rat"),this_object());
  }
    if (arg) return;
    set_short(
      "A dirt alley");
    set_long(
      "You have wandered into a very dusty and dirty alley. To the\n"+
      "west you can see a very large stone wall. The backs of\n"+
      "buildings and houses line the east side of the alley. There\n"+
      "is a lamp post here with a small lamp hanging from it.\n");
    set_weather(1, 4, 0);
    set_day_desc(
      "Even though it is day, it is still dimly lit in the alley.\n");
    set_night_desc(
      "It is very dark in the alley.\n");
    set_items
    (({
      "alley",
        "This is a very dirty alley.  It is very dark.",
      "lamp post",
        "This is a lamp post with a lamp on it.",
      "lamp",
        "This lamp is burning to keep the street light.",
      "stone wall#wall",
        "The stone wall is very tall, with cracks going up and down\n"
        "it's face. There are also some vines climbing up the wall.",
      "buildings#houses",
        "These buildings and houses line one side of the alley.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/alley2.c", "north",
      "/d/coronos/w/vorax/main2.c", "south",
    }));
  }
  
