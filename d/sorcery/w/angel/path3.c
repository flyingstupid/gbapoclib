#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the isle of sorcery");

  set_long(
"The mountain air is cool and crisp, forming little cloud vapours from your\n"+
"lips as you climb up the mountain side to its summit. The building is     \n"+
"clearer now, and you can make out a few towers rising from it. \n");

  set_items(({
"vapour#vapours#clouds",
"They are clouds of vapour formed from your breathing.\n",

"building#tower#towers",
"It looks like a wizards tower",
  }));

  set_listen("You can hear some birds chirping.\n");
  set_smell("The air smells cold...\n");
  set_exits(({
	"d/sorcery/w/angel/path4", "up",
	"d/sorcery/w/angel/path2", "down",
  }));
}


