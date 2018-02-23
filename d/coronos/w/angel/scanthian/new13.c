#include <mudlib.h>
#include "paths.h"
inherit ROOM;

void reset(status arg) {
   if(!arg) {
      set_short("the elfin forest");
      set_long(
"You are travelling deeper withing the forest.  In this part of the \n"+
"forest, lives a group of elfin thieves and bandits. \n");
     set_listen("You can hear the chirping of birds.\n");
     set_exits(({
	PATH+"new2", "southeast",
	PATH+"new14", "north",
     }));
     set_weather(1,4,3);
   }
}
