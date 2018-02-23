#include <mudlib.h>
inherit ROOM;
void reset(status arg)
{
   if(!present("girl")) {
     move_object(clone_object("/d/coronos/w/vorax/mon/girl.c"),
     this_object());
   }
   if (arg) return;
   set_short(
      "You are in a little girl's bedroom");
   set_long(
"The colors of the room lead you to believe this is the room of \n"+
"the family's only daughter. Stuffed bears line the room, and \n"+
"one sits upon the bed. A small rug lies on the floor.\n");
   set_weather(1, 2, 0);
   set_items
   (({
      "bears#small teddy bears#teddy bears", "These bears are all over the walls of this room.\n",
      "wallpaper", "This is a little girl's pink wallpaper.\n",
   }));
   set_exits
   (({
      "/d/coronos/w/vorax/h1r1.c", "down",
   }));
}
