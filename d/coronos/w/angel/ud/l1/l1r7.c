#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	if(arg) return;
	set_short("The long corridor");
  set_smell("It smells like orcs have been here recently.\n");
	set_listen("You hear moaning echoing from further within the caves. It\n"+
			"sounds like its getting a little closer.\n"); 
  set_long("You are standing in the middle of a natural corridor in the cave\n"+
					 "system. The floor is dusty and you leave tracks wherever you walk.\n");
	set_items(({
		"prints#tracks", "Footprints in the dust. It looks like yours are not\n"+
									"the only ones here."
	}));
	set_exits(({
	PATH+"/l1r8", "south",
	PATH+"/l1r6", "north",
	}));
	set_weather(0,1,0);
}



