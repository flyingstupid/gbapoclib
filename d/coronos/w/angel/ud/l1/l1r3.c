#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

object drow, orc;
int i;
void reset(status arg) {
	
  if(!drow) {
    drow = clone_object(MONST+"/drow1");
    move_object(drow, this_object());
  }

  if(!present("orc")) {
    for(i=0; i<5; i++) {
      orc = clone_object(MONST+"/orc2");
      move_object(orc, this_object());
    }
  }

	if(arg) return;
	set_short("The cave beginnings");
	set_smell("It smells like orcs and elves have been here.\n");
	set_long("You stand at the beginnings of a cave, your feet leaving tracks\n"+  
						"in the dusty floor. You get the feeling that this cave could be\n"+ 
						"quite larger than you first thought.\n");
	set_items(({
		"prints#tracks", "Footprints in the dust. It looks like yours are not\n"+
									"the only ones here."
	}));
	set_exits(({
	PATH+"/l1r2", "north",
	PATH+"/l1r5", "east",
	}));
	set_weather(0, 1, 0);
}



