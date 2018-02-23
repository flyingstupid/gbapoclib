#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"

inherit ROOM;

void reset(status arg) {
  object orc;
  int i;

  if(!present("orc")) {
    for(i=0; i<3; i++) {
      orc = clone_object(MONST+"/orc2");
      move_object(orc, this_object());
    }
  }

  if(!present("lieutenant")) {
    orc = clone_object(MONST+"/lieutenant");
    move_object(orc, this_object());
  }




 load_door(({
	"file", PATH"/cliff2",
	"direction", "west door",
	"long", "Not so much a door as a collection of planks nailed together.\n"+
					"It looks like it doesn't get used much at all.\n",
					}));
 if(arg) return; 
	set_short("Inside cliff");
	set_long(
	"Inside the cliff face the air is cool and moist, a vert difference\n"+
	"from the heat of the forest. This room looks as though it has \n"+
	"been turned into a small guard watch or post. There is a small fissure \n"+
	"in the south wall.\n");
	set_exits(({
	}));
	set_weather(0,3,0);
	set_items(({
	"south wall#fissure",
		"It looks like you may be able to squeeze through",
    "cliff face#cliff",
    "The inside of the cliff is smoother than the outside.\n",
	}));

	set_listen("You hear the sounds of water dripping onto rock coming from\n"+ 
		"deeper within the cave.\n");
	set_smell("The smell of Orc's is stronger here than outside.\n");
}



void init() {
  ::init();
  add_action("south", "south");
  add_action("south", "squeeze");
}

status south() {
  if(!this_player()->add_weight(5)) {
    write("You're carrying too much to fit through!\n");
    return 1;
  }
  this_player()->add_weight(-5);
  write("You squeeze through the fissure in the south wall.\n");
  this_player()->move_player("through the fissure in the south wall#"+
	PATH+"/l1r2");
  return 1;
}

