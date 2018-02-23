#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"
inherit ROOM;

void reset(status arg) {
   if(arg) return;
   set_short("the Ille Coronos docks");
   set_long(
      "The docks that serves as the main port for Ille Coronos ends\n"+
      "here and only continues northward.  To the south you see a long\n"+
      "stone formation jut out to meet the neverending ocean.  Overhead\n"+
      "you see seagulls flapping wildly in the wind and squawking just as\n"+
      "much.\n"
   );
   set_weather(1, 4, 6);
   set_smell("The air smells very salty.\n");
   set_listen("The waves crash against the beach close by.\n");
   set_exits(({
"d/coronos/w/alena/ille/d_1","northwest",
      STREETS+"dock4", "southwest",
   }));
}

