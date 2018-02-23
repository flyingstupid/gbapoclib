#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
  if(!present("guard")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/guard.c"),this_object());
  }
  reset_doors(arg);
  load_door(({
    "destination", "/d/coronos/w/vorax/street3.c",
    "direction", "iron gate",
    "long",
"A strong iron gate leading southward.\n",
    }));
  ::reset(arg);
  if(arg) return;
  set_short(
    "A cobblestone road");
  set_long(
  "This small cobblestone road stretches far to the north and south.\n"+
  "Passage to the south is blocked by a guardpost and gate, where a\n"+
  "City Guard can usually be found at his post.  The sound of the \n"+
  "ocean waves are very loud here, as they crash upon the shore.\n");
  set_weather(2, 4, 0);
  set_items
  (({
  "cobblestone road",
    "The cobblestone road is blocked here by a gate.",
  "guardpost",
    "There is usually a guard here.",
  "shore",
    "The sandy shore is to the west of here.\n",

  }));
  set_smell(
  "The smell of salt water is very strong here.\n");
  set_listen(
    "You can hear the crashing of waves along the shore.\n");
  set_exits
  (({
  "/d/coronos/w/vorax/street1.c", "north",
  }));
}
