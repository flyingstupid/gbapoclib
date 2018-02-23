#include <mudlib.h>
#include "paths.h"

inherit ROOM;

#define ELF 4 /* Number of elves */

object *elves;

void reset(status arg) {
  int i;
  object belf;
  
  if(!arg) {
     set_short("the elfin forest");
     set_long(
"You are at the western end of the forest. The forest is really dark here.\n"+
"You hear sounds from all around you, and none of them seem inviting. That\n"+
"once lovely sound of birds chirping, doesn't exist anymore. Many elves   \n"+
"hide in this darkness.\n");

    set_exits(({
	PATH+"new11", "north",
	PATH+"new9", "east",
    }));
    set_weather(1,4,3);
  }

}
