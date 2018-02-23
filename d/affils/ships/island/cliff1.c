#include <mudlib.h>
#define PATH "d/affils/ships/island"

inherit ROOM;

void reset(status arg) {
  load_door(({
	"direction", "east door",
	"long", "A door made from solid steel.\n",
	"file", "d/affils/rooms/tiamut",
  }));

  if(arg) return;

  set_short("Skol Island");
  set_long(
	"The waves crash on the rocks beneath your feet as you climb the\n"+
	"rising cliff face. There is a large flat platform here, and a  \n"+
	"door of solid steel in its face.\n");

  set_exits(({
        PATH+"/beach4", "west",
  }));

  set_weather(2, 1, 0);
}

