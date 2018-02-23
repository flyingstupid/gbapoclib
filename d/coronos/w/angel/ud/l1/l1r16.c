#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

object ob;
 void reset(status arg) {

  if(!ob) {
    ob = clone_object(MONST+"/kobold1");
    move_object(ob, this_object());
  }

	
	if(arg) return;
	set_short("a cave");
	set_long(
	"The cave here echoes the foot falls of your boots; an emptiness \n"+
	"contrasted by the stones that litter the floor.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r15", "north",
	}));
	set_weather(0, 1, 0);
}



