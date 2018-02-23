#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
  if(!present("begger")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/beg"),this_object());
  }
    if (arg) return;
    set_short(
      "A dark alley");
    set_long(
      "You are standing in a dark and dirty alley. There is a lot\n"+
      "of dust in the air here. The alley is very dark, and you can\n"+
      "hear drips of water coming from somewhere. There is a lamp\n"+
      "post here with a small lamp hanging on it.\n");
    set_weather(1, 4, 0);
    set_day_desc(
      "Very little sunlight peers into this alley.\n");
    set_night_desc(
      "The alley is very dark at night.\n");
    set_items
    (({
      "alley",
        "This is a very dark and dirty alley.",
      "lamp post",
        "This is a lamp post with a lamp hanging on it.",
      "lamp",
        "This lamp is burning to light the street.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/res4.c", "east",
      "/d/coronos/w/vorax/alley3.c", "west",
    }));
  }
  
