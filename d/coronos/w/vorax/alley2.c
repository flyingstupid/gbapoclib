#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
  if(!present("begger")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/beg"),this_object());
  }
    if (arg) return;
    set_short(
      "A dirt alley");
    set_long(
      "You are standing in a long and dark alley. It is very dusty\n"+
      "here. Perfect conditions for a dangerous alley rat or two.\n"+
      "The alley is lined with many houses and buildings around.\n"+
      "There is a lamp post here with a small lamp hanging from it.\n");
    set_weather(1, 4, 0);
    set_day_desc(
      "The alley is dimly lit.\n");
    set_night_desc(
      "The alley is very dark.\n");
    set_items
    (({
      "alley",
        "This is a very dark and dirty alley.",
      "lamp post",
        "This is a lamp post with a small lamp on it.",
      "lamp",
        "This lamp is lighting the street.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/alley3.c", "north",
      "/d/coronos/w/vorax/alley1.c", "south",
    }));
  }
  
