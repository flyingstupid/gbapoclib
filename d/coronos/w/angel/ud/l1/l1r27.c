#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

 void reset(status arg) {
  int i;
  object ob;

  if(!present("drow")) {
    for(i=0; i<4; i++) {
      ob = clone_object(MONST+"/drow2");
      move_object(ob, this_object());
    }
  }
	
	if(arg) return;
	set_short("a cave");
	set_long(
	"Darkness clings to the walls in this part of the cavern system.\n"+
	"Plooms of steam come up from your mouth.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
	"darkness", "It clings to the walls in an attempt to hide from you",
	"wall#walls", "They are bathed in darkness",
	"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r28", "south",
	PATH+"/l1r26", "north",
	}));
	set_weather(0, 1, 0);
}



