#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the isle of sorcery");

  set_long(
"The mountain summit is high above the sea, and from here you can see the \n"+
"whole north side of the island. There is a large building with many towers\n"+
"rising from its high walls ahead. It looks similar in design to typical   \n"+
"abodes of wizards you have seen around the realms of Magia, but the towers\n"+
"here are higher, and more grand than you have ever seen. It is as if the  \n"+
"whole place was created by magic; an impressive sight indeed.\n");

  set_weather(2, 1, 0);

  set_items(({
"sea",
	"The sea is far below you. It almost makes you feel giddy.\n",
"walls#wall", 
"The walls seem to rise out of the ground as single pieces of basalt!\n",

"vapour#vapours#clouds",
"They are clouds of vapour formed from your breathing.\n",

"tower#towers",
"The towers of High Sorcery",
  }));

  set_exits(({
	"d/sorcery/w/angel/path3", "down",
	"d/sorcery/w/angel/path5", "south",
  }));

  set_listen("You can almost hear the magic from the hallowed halls beyond.\n");
  set_smell(
	"You can almost smell the magic fromthe hallowed halls beyond!\n");
}

