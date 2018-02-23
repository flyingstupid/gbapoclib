#include <mudlib.h>

#define PATH "d/coronos/w/angel/ud/l1/"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("a cave");
  set_long(
	"Stones litter the floor, as if scattered around by some \n"+
	"great angry creatures. The air here is cool, blowing in  \n"+
	"from the north. Some phospherescent moss lights the cave\n"+
	"givings its appearance a somewhat eerie feel.\n");

  set_items(({
	"stone#stones",
	"They are but small pebbles, and almost completely round",
	
	"moss#light#lights",
	"The moss is a soft green colour and seems to glow",
  }));

  set_listen(
	"As the air rushes past your ears you can make out the \n"+
	"soft voices of a drow scout party just to the north.\n");
  set_smell("You can smell that orcs have been through here.\n");
	
  set_weather(2, 1, 0);

  set_exits(({
	PATH+"l1r10", 	"south",
	PATH+"n_path2", "north",
  }));
}
