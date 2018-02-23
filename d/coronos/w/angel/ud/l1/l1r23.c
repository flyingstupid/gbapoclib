#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
 load_door(({
	"file", PATH+"/l1r22",
	"direction", "north door",
	"long", "Not so much a door as a collection of planks nailed together.\n"+
					"It looks like it doesn't get used much at all.\n",
					}));
	
	if(arg) return;
	set_short("a cave");
	set_long(
	"A small cave with a few stones on the ground.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	}));
	set_weather(0, 1, 0);
}



