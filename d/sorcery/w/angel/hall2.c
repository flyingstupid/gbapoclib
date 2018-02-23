#include <mudlib.h>
inherit ROOM;

object ob;
void reset(status arg) {
  if(!ob) {
    ob = clone_object("/d/sorcery/w/angel/monst/dillan");
    move_object(ob, this_object());
  }
  reset_doors(arg);
  if(!present("white chair")) {
    move_object(clone_object("d/ooc/w/alena/white_chair"), this_object());
  }

  if(arg) return;

  load_door(({
	"file", "d/affils/rooms/wrm",
	"direction", "east door",
	"long",
	"A fine door of sturdy oak.\n",
  }));


  set_short("the tower of sorcery");
  set_long(
"There is a landing here, amid the darkness of the halls of the \n"+
"tower of high sorcery. A simple chair of white leather stands  \n"+
"outside a door that bears a single white circle of protection  \n"+
"on it. A torch hangs in a silver sconce to the left of the door.\n"+
"The stairs continue up and down from this landing.\n");

  set_items(({
	"circle",
	"A white circle of protection",

	"shapes#dark shapes",
	"Perhaps they are just shadows, or the long dead spirits \n"+
	"of those who have died here in horrible magical experiments",

	"torch#torches",
	"The torches are lit and flickering, granting some warmth \n"+
	"to these almost empty halls within the tower",

	"sconce",
	"A silver torch sconce",

	"darkness", "Its very black!",
	"stairs#staircase",
	"A long staircase that leads downward",
  }));

  set_listen("You can hear voices from the other side of the door.\n");
  set_smell("The air smells of old books and wood.\n");


  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/hall1", "up",
	"d/sorcery/w/angel/hall3", "down",
  }));
}

