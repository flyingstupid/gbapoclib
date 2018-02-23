#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;

  load_door(({
	"direction", "east door",
	"file", "d/sorcery/w/angel/lib",
	"long",
	"A large oaken door that bears a small plaque:\n"+
	"\tThe Library\n",
  }));


  set_short("the tower of sorcery");

  set_long(
"You stand in a simple hallway, lined with a dark marble, that extends \n"+
"to the west. Torches light the way through the cold air toward a door \n"+
"at the end of the corridor.\n");

  set_items(({
"hallway#corridor",
"A long hallway which leads only to the door at its end",
"torch#torches",
"Torches line both sides of the wall, shedding light into this dark place",
  }));

  set_listen("You can hear soft talking from the east of the hallway.\n");
  set_smell("The air is full of the smell of old books.\n");

  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/ehall1", "west",
  }));
}

