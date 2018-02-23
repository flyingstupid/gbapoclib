#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	reset_doors(arg);

	if(arg) return;

  load_door(({
    "file", PATH+"/n_path1",
    "secret door", 15,
    "long", "A secret door in the north wall",
    "secret door finders", ({}),
    "direction", "north door",
  }));


	set_short("a cave");
	set_long(
  "Darkness shrouds the walls within this section of cave.\n"+
  "The all too familiar picture of stones litter the floor here as well.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r11", "south",
	PATH+"/l1r17", "east",
	}));
	set_weather(0, 1, 0);
}



