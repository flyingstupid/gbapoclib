#include <mudlib.h>
#include "paths.h"

inherit ROOM;


void reset(status arg) {
  load_door(({
	"file", DARKNESS+"wallst0",
	"direction", "south gate",
	
	"lock description", "A large iron lock.\n",
	"long",
	"A large iron gate\n",
  }));
  if(!arg) {
    set_short("Forest path");
    set_long(
  "A large gate to the south marks the entrance to the grand city of \n"+
  "Ille Coronos, while a simple road winds its way into the north where \n"+
  "you can spot farming land and the rolling slopes that mark the foothills\n"+
  "of Darken Mountain.\n");
  set_exits(({
	"d/coronos/w/angel/city/roads/road1", "north",
    }));
    set_weather(2,4,3);
  }
}

