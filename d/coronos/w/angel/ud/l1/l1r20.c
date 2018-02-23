#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

 void reset(status arg) {
  if(!present("wyvern")) {
    move_object(clone_object(MONST+"/wyvern"), this_object());
  }

	
	if(arg) return;
	set_short("a cave");
	set_long(
"The cave here is quite and dark, the perfect place to hide.\n"+
"A large hole in the centre of the cave looks very ominous.\n");
	set_smell("It smeels like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
                "hole",
                "The hole looks rather steep. You had better know your climbing well "+
                "before you climb down there",
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
        set_climb(15);
        set_fall_dam(20);

	set_exits(({
	PATH+"/l1r21", "south",
        PATH+"/l1r40", "down",
	PATH+"/l1r24", "east",
	PATH+"/l1r19", "north",
	}));
	set_weather(0, 1, 0);
}



void init() {
 ::init();
  add_action("down", "down");
}

status down() {
  if(present("wyvern")) {
    write("The Wyvern blocks your path.\n");
    return 1;
  }
}

status query_no_teleport() { return 1; }
