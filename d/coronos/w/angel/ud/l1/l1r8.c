#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

int i;
object ob;
 void reset(status arg) {

  if(!present("scorpion")) {
    for(i=0; i<8; i++) {
      move_object(clone_object(MONST+"/scorpion"), this_object());
    }
  }

	
	if(arg) return;
	set_short("Corridor T-intersection");
  set_smell("It smells like orcs have been here.\n");
	set_listen("You hear moaning echoing from further within the cave.\n"+
			"Its sounds quite close.\n");
	set_long("You are standing at an intersection in the cave. A side passage\n"+
					 "leads to the east whilst the corridor continues to the south.\n"+
					 "Your feet kick up small plumes of dust with every step.\n");
	set_items(({
		"prints#tracks", "Footprints in the dust. It looks like yours are not\n"+
									"the only ones here."
	}));
	set_exits(({
	PATH+"/l1r9", "south",
	PATH+"/l1r13", "east",
	PATH+"/l1r7", "north",
	}));
	set_weather(0, 1, 0);
}



