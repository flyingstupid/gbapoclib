#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("a cave");
	set_long(
  "The cave walls are covered with scratches here, and there are some \n"+
  "dark stains on the floor amid the little rocks that litter the cave.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
	"walls",
	"They are covered in scratches",
	"scratches", "They look like they were made by a very large creature",
	"floor", "There are dark stains on the floor",
	"stains#stain", "It looks a little like blood, but there is no body",
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r10", "west",
	PATH+"/l1r19", "east",
	}));
	set_weather(0, 1, 0);
}



