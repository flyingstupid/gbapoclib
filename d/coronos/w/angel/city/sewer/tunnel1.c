/* Thief tunnel1 */
#define PATH	"d/coronos/w/angel/city/sewer/"


#include <mudlib.h>
#include  "/include/fn/linewrap.h"
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
    "direction", "trap door",
	"file", "d/coronos/w/angel/city/docks/dock1",
    "long",
      "A trap door in the ceiling.\n",
  }));
  if(arg) return;

  set_short("A dark damp tunnel beneath the city");
  set_long(lw(
    "Water that drips down the walls in this small round tunnel "+
    "meanders it's way around underneath the city above.\n"));

  set_exits(({
	PATH+"tunnel2", "east",
  }));

  set_weather(0, 1, 0);
  set_listen("You hear the dripping of water off the walls...");
  set_smell("The air about you smells damp and musty...");
}
