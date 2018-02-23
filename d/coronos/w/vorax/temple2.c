#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if(!present("preacher")) {
      move_object(clone_object("/d/coronos/w/vorax/mon/preacher.c"),
      this_object());
    }
    if (arg) return;
    set_short(
      "In the preacher's workroom");
    set_long(
      "You are standing in the preacher's workroom.  In the\n"+
      "very middle of the room there is a workdesk that the\n"+
      "preacher will write his sermons in before he goes into\n"+
      "the church.\n");
    set_weather(1, 4, 0);
    set_items
    (({
      "workdesk",
        "This is the preacher's workdesk.",
      "church",
        "The church is outside the doorway.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/temple1.c", "out",
    }));
  }
  
      
