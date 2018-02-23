#include <mudlib.h>
#include "path.h"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

void reset(status arg) {
  object orc;
  int i;

  if(!present("orc")) {
    for(i=0; i<3; i++) {
      orc = clone_object(MONST+"/orc1");
      move_object(orc, this_object());
    }
  }


	
 load_door(({
	"file", PATH+"/lvl1",
	"direction", "east door",
	"long", "Not so much a door as a collection of planks nailed together.\n"+
					"It looks like it doesn't get used much at all.\n",
					}));
	
	if(arg) return;
	set_short("The Cliff Base");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
  set_long("The cave is dark and smelly, but provides some protection\n"+
  "should the elements outside turn bad. The rocks from \n"+
  "the slide seem not to have penetrated too far inside \n"+
  "the cave mouth.\n");

	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	ROADS+"mount_pass", "south",
	}));
	set_weather(1,4,0);
}



