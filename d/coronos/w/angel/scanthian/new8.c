#include <mudlib.h>
#include "paths.h"

inherit ROOM;

#define ELF 4

object *elves;

void reset(status arg) {
   int i;
   object dgg, delf;
   




   if(!arg) {
     set_short("the elfin forest");
     set_long(
"You have stepped into the dark part of the forest. This is the place \n"+
"where all the outcast elves abide, those that dwell in darkness. It is\n"+
"said that they do not take too kindly to visitors.\n");

     set_exits(({
	PATH+"new2", "east",
	PATH+"new9", "west",
     }));
     set_weather(1,4,3);
  }
}
