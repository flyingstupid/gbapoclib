#include <mudlib.h>
inherit ROOM;
void reset(status arg)
   {
      if (arg) return;
      set_short(
         "This is a kitchen");
      set_long(
         "This is a fairly spacious kitchen.  It looks like it\n"+
         "might also serve as a living room.  There is a table\n"+
         "and some chairs in the corner of the room.  There is\n"+
         "also a television set sitting in the other corner of\n"+
         "the room.\n");
      set_weather(1, 2, 0);
      set_items
      (({
         "kitchen",
            "Just look around you, you're standing in it.",
         "living room",
            "Just look around you, you're standing in it.",
         "table",
            "This is just a normal table with a few chairs around it",
         "chairs",
            "These chairs are just sitting around the table.",
         "television set#television",
            "This television is very old and hasn't been used for\n"+
            "awhile.",
      }));
      set_exits
      (({
         "/d/coronos/w/vorax/h2r1.c", "east",
         "/d/coronos/w/vorax/h2r3.c", "north"
      }));
   } 
