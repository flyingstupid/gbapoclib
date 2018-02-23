#include <mudlib.h>
#include "paths.h"
inherit ROOM;


void reset(status arg) {
   if(!present("gzabo")) {
     move_object(clone_object("room/city/monst/giant"),this_object());
   }

   if(!arg) {
      set_short("the elfin forest");
      set_long(
"You are still deep within the forest.  A thick mist has fallen over\n"+
"this part of the forest.  Snakes and other animals have been known to\n"+
"lurk in such conditions.\n");
      set_exits(({
	PATH+"new11", "west",
	PATH+"new9", "south",
       }));
      set_weather(1,4,3);
      set_smell("You can smell pine and oak in the thick forest.\n");
    }
}
