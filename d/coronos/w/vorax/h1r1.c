#include <mudlib.h>
inherit ROOM;
void reset(status arg)
   {
      if (arg) return;
      set_short(
         "A Living Room");
      set_long(
	  "This fairly spacious house is owned by Galdon, a local business\n"+
	  "man who runs the general store. The room itself is fairly spacious\n"+
	  "for a simple merchant, and has a huge stained glass window, making\n"+
         "up half of one wall.  There is one reclining chair here.\n"+
         "In one corner of the room is a staircase leading upstairs.\n");
      set_weather(1, 2, 0);
      set_items
      (({
         "window#glass window", "This is a huge glass window\n"+
         "that looks out over the ocean.\n", }));
      set_exits
      (({
         "/d/coronos/w/vorax/h1r2.c", "up",
          "/d/coronos/w/vorax/res2.c", "west",
      }));   }
   
   
