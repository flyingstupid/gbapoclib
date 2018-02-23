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

  if(!present("drow")) {
    for(i=0; i<4; i++) {
      ob = clone_object(MONST+"/drow2");
      move_object(ob, this_object());
    }
  }

	
  reset_doors(arg);
	if(arg) return;


	set_short("a cave");
	set_long(
"The cave here seems quiet and devoid of life, except perhaps for the \n"+
"all too familiar rocks that litter the floor about you.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r16", "south",
	PATH+"/l1r13", "northwest",
	PATH+"/l1r14", "north",
	}));
	set_weather(0, 1, 0);
}



