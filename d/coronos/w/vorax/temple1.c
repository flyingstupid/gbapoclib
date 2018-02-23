#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Inside a temple");
    set_long(
      "You are standing inside a temple.  There are many\n"+
      "benches sitting around, so that the congregation\n"+
      "can sit down while the preacher is speaking.  At\n"+
      "the back of the temple you can see a small doorway\n"+
      "that is open.\n");
    set_weather(1, 4, 0);
    set_items
    (({
      "temple",
        "This is a small temple.",
      "benches",
        "These benches are for the congregation to sit on.",
      "doorway",
        "This is a small doorway leading to the preacher's room.",
    }));
    set_exits
    (({
	"d/affils/rooms/st-arion", "doorway",
      "/d/coronos/w/vorax/west8.c", "north",
    }));
  }

