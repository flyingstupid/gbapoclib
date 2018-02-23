#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

 void reset(status arg) {
	
	reset_doors(arg);
	load_door(({
		"direction", "west door",
		"file", PATH+"/l1r11",
		"long",
			"A secret door in the west wall.\n",
    "secret door finders", ({}),
    "secret door",	9,
	}));
 
	if(arg) return;
	set_short("a cave");
	set_long(
	"This section of the dark caves seem to be well travelled. The \n"+
	"stones that littered the floor in the other section of the caves\n"+
	"are missing from here.\n");
  set_smell("It smells like orcs and elves may have been here,n"+
		"but not recently.\n");
	set_items(({
	"rock#rocks", "There are none here!",
	"floor", "The floor has many footprints on it",
	"prints#foot prints",
	"There are many different prints on the floor, but they are not yours",
	}));
	set_weather(5,5,5);
}



