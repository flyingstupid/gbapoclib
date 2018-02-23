#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"
inherit ROOM;

void reset(status arg) {
  if(!present("greeli")) {
    move_object(clone_object("d/coronos/w/angel/city/monst/greeli"),
    this_object());
  }

   if(arg) return;
   set_short("the Ille Coronos docks");
   set_long(
      "The docks that serves as the main port for Ille Coronos ends\n"+
      "here and only continues northward.  To the north you see a long\n"+
      "stone formation jut out to meet the neverending ocean.  Overhead\n"+
      "you see seagulls flapping wildly in the wind and squawking just as\n"+
      "much.\n"
   );
   set_weather(1, 4, 6);
   set_smell("The air smells very salty.\n");
   set_listen("The waves crash against the beach close by.\n");
   set_exits(({
      STREETS+"dock2", "northeast",
      "d/coronos/w/angel/city/docks/dock6", "northwest",
   }));
}

