#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;

  load_door(({
	"file", "d/sorcery/w/angel/chamber1",
	"direction", "south door",
	"long",
	"A large set of double doors with a single circle of \n"+
	"protection in its centre in three colours; white, grey, "+
	"and black",
  }));

  set_short("the tower of sorcery");
  set_long(
"You stand in the hallowed halls of the tower of high sorcery.\n"+
"Dark shapes loom about the walls, while torches flicker and  \n"+
"crackle nearby. A pair of large oaken double doors stand to  \n"+
"the south, leading into the chambers of the Council of the   \n"+
"Nine, and a long stair case winds downward into the darkness \n"+
"to the north.\n");

  set_items(({
	"shapes#dark shapes",
	"Perhaps they are just shadows, or the long dead spirits \n"+
	"of those who have died here in horrible magical experiments",

	"torch#torches",
	"The torches are lit and flickering, granting some warmth \n"+
	"to these almost empty halls within the tower",

	"darkness", "Its very black!",
	"circle",   "A circle of protection",
	"stairs#staircase",
	"A long staircase that leads downward",
  }));

  set_listen("All you can hear is the flickering of torches.\n");
  set_smell("The air smells of old books and wood.\n");


  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/hall2", "down",
  }));
}
