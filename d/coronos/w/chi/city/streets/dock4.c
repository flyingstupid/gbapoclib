#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"
inherit ROOM;

void reset(status arg) {
   if(arg) return;
   set_short("the Ille Coronos docks");
   set_long(
      "You are just north of a long stretch of stone that extends\n"+
      "outward from the beach, down to a set of large pylons. Here,\n"+
      "as the waves crash against the beach, and the sea gulls squawk\n"+
      "noisly, the great merchant ships bring their cargo to sell in\n"+
      "the markets of Ille Coronos.\n"
   );
   set_weather(1, 4, 6);
   set_smell("The air smells very salty.\n");
   set_listen("The waves crash against the beach close by.\n");
   set_exits(({
	"d/coronos/w/angel/city/docks/dock1", "southwest",
      STREETS+"dock5",                       "northeast",
   }));
}

