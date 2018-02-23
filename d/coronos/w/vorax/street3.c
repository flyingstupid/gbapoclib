#include <mudlib.h>
inherit ROOM;
void reset (status arg) {
  reset_doors(arg);
  load_door(({
  "destination", "/d/coronos/w/vorax/street2.c",
  "direction", "iron gate",
  "long",
  "A large iron gate that leads northward.\n",
  }));
  ::reset(arg);
  if(arg) return;
  set_short("A small cobblestone road");
  set_long(
  "This small cobblestone road leads far to the north, at which point\n"+
  "it seems to be blocked off by a gate.  A small guardpost also stands\n"+
  "on the other side of the gate.  The sound of the ocean waves are\n"+
  "very loud here, as they crash upon the shore.\n");
  set_weather(2, 4, 0);
  set_items
  (({
  "cobblestone road",
    "The cobblestone road is uneven and hard to walk on.",
  "guardpost",
    "The guardpost is on the other side of the gate.",
  "shore",
     "The sandy shore is to the west.\n",
  }));
  set_exits(({
  "/d/coronos/w/russkie/rooms/1", "southeast",
  }));
  set_listen("You hear the crashing of waves along the shore.\n");
}
