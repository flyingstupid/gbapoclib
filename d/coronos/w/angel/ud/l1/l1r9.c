#include <mudlib.h>
#define MONST	"d/coronos/w/angel/ud/monst"
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	

	if(arg) return;
	set_short("The Cliff Base");
	set_smell("Your nose wrinkles in disgust at the stench of rotting vegetables.\n");
	set_long(
	"There is a solid wall of stone which blocks the path southward.\n"+
	"There are still several sets of footprints on the cave floor.\n");
	set_items(({
	"wall#stone wall",
	"The cave ends here in a wall of stone",
		"prints#tracks", "Footprints in the dust. It looks like yours are not\n"+
									"the only ones here."
	}));
	set_exits(({
	PATH+"/l1r8", "north",
	}));
	set_weather(0,1,0);
}



