#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	load_door(({
		"file", PATH+"/l1r18",
		"long", "A secret door in the east wall",
		"secret door", 10,
		"secret door finders", ({}),
		"direction", "east door",
	}));
	
	if(arg) return;
	set_short("a cave");
	set_long(
"Dark is the only way to describe this small cave. The walls close in \n"+
"on you and the air is a little stale here.\n");
	set_smell("The stench of orcs pervades the hall.\n");
 set_listen("You think you hear murmuring coming from behing the east wall\n");
	set_items(({
	"walls",
	"They are dark and cold",
	"prints#tracks", "Footprints in the dust. It looks like yours are not\n"+
	"the only ones here, with one set leading towards the east wall."
	}));
	set_exits(({
	PATH+"/l1r12", "south",
	PATH+"/l1r10", "north",
	}));
	set_weather(0, 1, 0);
}



