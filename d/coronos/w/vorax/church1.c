#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Inside a small church");
    set_long(
      "You are standing inside a small, yet finely decorated\n"+
      "church.  The ceiling of the church is built like a\n"+
      "small pyramid.  Toward the front of the church is\n"+
      "a retangular podium where the preacher would normally\n"+
      "stand to give his sermon.  There is no one in the\n"+
      "church right now which makes you wonder where they\n"+
      "are.\n");
    set_weather(1, 4, 0);
    set_items
    (({
      "church",
        "This is a small very decorative church.",
      "ceiling",
        "The ceiling is very high, and pointed at the top.",
      "podium",
        "This is a small podium where the preacher would stand.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/slate2.c", "west",
    }));
  }

      
      
