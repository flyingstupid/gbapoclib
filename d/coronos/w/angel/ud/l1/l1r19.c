#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("a cave");
	set_long(
  "There are hundreds bones here, scattered amid the rocks that lay strewn \n"+
  "all over the cave floor.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
        set_listen("You can hear the noise of a large hungry creature from the south.\n");
	set_items(({
        "bones", 
        "There are literally hundred of bones strewn around the room, as if \n"+
        "some great horrible creature ripped them appart while they still lived. \n"+
        "The cave here, and beyond, certainly smells of death...\n",
	"demi humans",
	"floor", "There are many small stones and rocks on the floor",
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r20", "south",
	PATH+"/l1r17", "west",
	}));
	set_weather(0, 1, 0);
}



