#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
        reset_doors(arg);

	if(arg) return;



	load_door(({
          "file", PATH+"/l1r29",
          "direction", "west door",
          "long", "An irregularity in the wall. Perhaps it leads somewhere?\n",
          "secret door", 15,
          "secret door finders", ({ }),
	}));

	set_short("a cave");
	set_long(
  "Many small stones litter the ground, covered in frost from the \n"+
  "chill of the air. Shadows cling to the walls giving this part  \n"+
  "of the cave a sinister feeling.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
	"frost", "It makes the stones look almost blue",
	"shadows#shadow", "I wouldn't look there if I were you",
	"wall#walls", "They are covered in darkness",
		"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r27", "north",
	}));
	set_weather(0, 1, 0);
}



