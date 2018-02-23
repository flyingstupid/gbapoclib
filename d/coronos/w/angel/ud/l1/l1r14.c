#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("a cave");
	set_long(
"Darkness shadows the corners of the walls of the cave, leaving you \n"+
"feeling terrible alone, save for the rocks on the floor.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
	"walls",
	"They are shadowed in darkness",
	"darkness",
	"You shouldn't look in there. You may never know what lerks within",
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r15", "south",
	PATH+"/l1r12", "north",
	}));
	set_weather(0, 1, 0);
}



