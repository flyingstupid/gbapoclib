#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    int i;
    object obj;
    if(!present("guard")) {
	for(i=0; i<2; i++) {
	    obj = clone_object("room/city/monst/guard1");
	    move_object(obj,this_object());
	}
    }

    if(arg) return;
    set_short("the corridors of the town hall");
    set_long(
      "The sounds of your footsteps echo loudly throughout the \n"+
      "long corridor that runs south from the Great Hall. There\n"+
      "are a few paintings along the sides of the walls, in a  \n"+
      "pleasant display of art work. \n");
    set_weather(2,1,0);
    set_exits(({
	"room/city/t_hall2", "south",
      }));
    set_items(({
	"painting#paintings",
	"A few beautiful water colours decorate the walls of this hallway.\n"+
	"One depicts a dark wood, shadowy and frightening, while the other\n"+
	"is of a beautiful glen, and a few sprites enjoying its tranquility",

	"wood#dark wood",
	"The woods in the painting are dark and sinister. They remind you \n"+
	"of the stories you have heard about the forest outside the city walls",

	"shadows",
	"The shadows cast dark shapes over the trees",

	"glen",
	"A beautiful, peaceful and tranquil glen",
	"sprites",
	"They play happily in the sun light in the painting",
	"sun#light#sun light",
	"The sun sets in the painting over a small mountain, whose crest can\n"+
	"be seen just above the tips of the tree tops of the peaceful forest",
	"mountain#crest",
	"Upon the crest of the mountain you can see a small hut",
	"hut",
	"It appears to be a log cabin, beside it you spy an angelic figure",
	"figure",
	"It looks like Angel, the founder of Tempus. Perhaps he lives \n"+
	"somewhere on a mountain crest like this one, outside the city",
      }));
}



