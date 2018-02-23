#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

 void reset(status arg) {
  int i;
  object ob;

  if(!present("orc")) {
    for(i=0; i<6; i++) {
      ob = clone_object(MONST+"/orc1");
      move_object(ob, this_object());
    }
  }

	
	if(arg) return;
	set_short("The long corridor");
	set_smell("The orcish stench you've been smelling all along seems to be \n"+
					"getting stronger.\n");
	set_long("You are standing at the northern end of a long corridor leading\n"+
					 "south. The floor is very dusty here, and your feet leave deep\n"+
						"prints wherever you walk.\n");
	set_items(({
		"prints#tracks", "Footprints in the dust. Not all of them are yours, some\n"+
		"look like they could almost be orcish"
	}));
	set_exits(({
	PATH+"/l1r6", "south",
	PATH+"/l1r3", "west",
	}));
	set_weather(0, 1, 0);
}



