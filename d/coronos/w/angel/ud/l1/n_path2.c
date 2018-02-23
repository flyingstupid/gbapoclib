#include <mudlib.h>

#define PATH "d/coronos/w/angel/ud/l1/"
#define MONST "d/coronos/w/angel/ud/monst/"

inherit ROOM;

void reset(status arg) {
object drow, mage;
int i;

  if(!present("mage")) {
    mage = clone_object(MONST+"mage1");
    mage -> set_aggressive(1);
    move_object(mage, this_object());
  }

  if(!present("scout")) {
    for(i=0; i<3; i++) {
      drow = clone_object(MONST+"drow2");
      drow -> set_aggressive(1);
      move_object(drow, this_object());
    }
  }

  if(arg) return;

  set_short("a cave");
  set_long(

"The glow of moss lights a path further northward, sloping \n"+
"further down into the earth. There are fewer stones here, \n"+
"and the path appears not to have been used as much as in  \n"+
"other areas of the caves. \n");

  set_items(({
	"stone#stones",
	"They are but small pebbles, and almost completely round",
	
	"moss#light#lights",
	"The moss is a soft green colour and seems to glow",

	"ceiling",
	"You can see the formation of stalectites.\n",
  }));


  set_listen("You can hear the occasional drip of water from "+
	"the ceiling.\n");
	
  set_smell("You can smell that orcs have been through here.\n");
	
  set_weather(2, 1, 0);

  set_exits(({
	PATH+"n_path1", 	"south",
	PATH+"n_path3", 	"north",
  }));
}


void init() {
  ::init();
  add_action("north", "north");
}

status north() {
object obj;

  if(obj=present("dark elf")) {
    write(obj->short()+" bars your way!\n");
    return 1;
  }
  return 0;
}

