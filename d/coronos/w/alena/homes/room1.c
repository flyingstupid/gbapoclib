
#include <mudlib.h>


inherit ROOM;
void reset(status arg) {
    if(arg) return;

    set_short("blah");
    set_long(
      "Blah \n"+
      "light the ways throughout the clerists tower.\n");

    set_items(({
	"floor#marble#reflection",
	"You can see yourself in the reflection in the higly polished "+
	"marble floor",

      }));

    set_weather(2, 1, 0);

    set_exits(({
	"/d/coronos/w/vorax/res5","west",
      }));
}



