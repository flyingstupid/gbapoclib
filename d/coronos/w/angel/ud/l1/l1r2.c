#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"

inherit ROOM;

void reset(status arg) {
	
	if(arg) return;
	set_short("Inside the cave");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_listen("You hear a soft moaning, caused by air moving through the fissure.\n");
	set_long("You are standing inside a cave. The floor is dry and dusty, and\n"+
					 "your boots leave prints in the soft dust. Little light manages to\n"+
					 "filter through the fissure, and the cave is dark further on.\n");
	set_items(({
		"prints#tracks", "Foot prints in the dust. It looks like yours are not\n"+
									"the only ones here."
		"fissure#north wall",
		"It is a narrow fissure that you might be able to squeeze "+
		"through\n",
	}));
	set_exits(({
	PATH+"/l1r3", "south",
	}));
	set_weather(0, 1, 0);
}



void init() {
  ::init();
  add_action("north", "north");
  add_action("north", "squeeze");
}

status north() {
  if(!this_player()->add_weight(5)) {
    write("You're carrying too much to fit through the fissure.\n");
    return 1;
  }
  this_player()->add_weight(-5);
  write("You squeeze through the fissure in the north wall.\n");
  this_player()->move_player("through the fissure in the north wall#"+
	PATH+"/lvl1");
  return 1;
}

