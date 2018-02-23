#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("The long corridor");
	set_smell("The smell of orcs is getting stronger.\n");
	set_listen("You hear a moaning echoing from further within the cavern,\n"+
					"although you're not sure whats causing it.\n");
	set_long("You are in a corridor running north south. The floor is dry and\n"+
           "dusty, your feet leaving tracks in the soft ground.\n");
	set_items(({
		"prints#tracks", "Footprints in the dust. Not all of them are yours, some\n"+
		"look like they could almost be orcish"
	}));
	set_exits(({
	PATH+"/l1r7", "south",
	PATH+"/l1r5", "north",
	}));
	set_weather(0, 1, 0);
}



