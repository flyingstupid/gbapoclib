#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("a cave");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_long(
	"The cave is dark and cold. The stones have some frost on them.\n");
	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	"frost", "It clings to the rocks like a christmas ornament",
	}));
	set_exits(({
	PATH+"/l1r27", "south",
	PATH+"/l1r24", "north",
	}));
	set_weather(0, 1, 0);
}



