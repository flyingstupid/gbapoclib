#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("a cave");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_long(
	"Small plumes of dust kick up from the floor as you walk along the \n"+
	"dark corridor of this small cave. Many rocks abound on the cave "+
	"floor.\n");
	set_items(({
	"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
	"they might have been used to fill over the cave enterance."
	"dust", "In the dust you can see footprints",
	"prints#footprints",
	"They don't look like yours",
	}));
	set_exits(({
	PATH+"/l1r15", "southeast",
	PATH+"/l1r8", "west",
	PATH+"/l1r12", "northeast",
	}));
	set_weather(0, 1, 0);
}



