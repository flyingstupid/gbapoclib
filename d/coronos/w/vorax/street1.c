#include <mudlib.h>
inherit ROOM;
void reset (status arg)
  {
  ::reset(arg);
  if(arg) return;
  set_short(
    "A small stretch of cobblestone road\n");
  set_long(
  "This small stretch of cobblestone road runs a straight path through\n"
  "Coronos.  The large stone wall casts eerie shadows over the stones.\n"
  "and makes the sunlight dance over the road ahead.  The sound of\n"
  "waves crashing hangs in the air.\n");
  set_weather(2, 4, 0);
  set_items
  (({
    "cobblestone road",
      "The cobblestones are uneven and hard to walk on.",
    "stone wall#wall",
      "The stone wall looms over the road.",
  }));
  set_smell(
    "The smell of salt water hangs in the air.\n");
  set_listen(
      "The sound of waves crashing violently against the shore hangs in the air.\n");
  set_exits
  (({
    "/d/coronos/w/vorax/street2.c", "south",
    "/d/coronos/w/vorax/west1.c", "north",
  }));
}
