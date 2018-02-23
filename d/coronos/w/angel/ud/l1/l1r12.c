#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("a cave");
	set_long(
"This site within the cave bears litterally hundreds of small rocks \n"+
"on it's floor. Perhaps this site was used as a mine or quarry.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
	"floor",
	"It's covered in a thousand or so small rocks",
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r14", "south",
	PATH+"/l1r13", "southwest",
	PATH+"/l1r11", "north",
	}));
	set_weather(0, 1, 0);
}



