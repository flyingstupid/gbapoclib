#include <mudlib.h>
#include "paths.h"
inherit ROOM;

void reset(status arg) {
  if(!arg) {
     set_short("the elfin forest");
     set_long(
"The forest seems to get darker in these parts.  There is a strong sense \n"+
"of evil in the air.  The trees aren't even the same.  They seem to be of \n"+
"poorer quality, and all of their leaves have either fallen off, or turned\n"+
"brown.\n");

    set_exits(({
	PATH+"new8", "east",
	PATH+"new12", "north",
	PATH+"new10", "west",
    }));
    set_weather(2,4,3);
  }
}
