#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
 load_door(({
	"file", PATH+"/l1r23",
	"direction", "south door",
	"long", "Not so much a door as a collection of planks nailed together.\n"+
					"It looks like it doesn't get used much at all.\n",
					}));
	
	if(arg) return;
	set_short("a cave");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_long(
	"There are planks of wood around a small doorway, amid a collection.\n"+
	"of assorted rocks.\n");
	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r21", "north",
	}));
	set_weather(0, 1, 0);
}



