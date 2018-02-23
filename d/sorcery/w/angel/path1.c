#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the isle of sorcery");

  set_long(
"The long basalt path winds further into the mountains, leaving the \n"+
"serenity of the sea and beach below. High on the mountain tops you \n"+
"can see a building of some sort.\n");

  set_items(({
"mountain#mountains",
"They appear very tall. It will take quite a long way to walk the long\n"+
"path upward to its top. At its peaks you can see a tall building.\n",

"building",
"It has many tall towers",
"tower#towers",
"There is a light in one of the windows",

"light#window",
"The window is lit, but you cant see anything else from this distance",

"ocean#wave#waves#sea",
"The waves crash against the beach, washing some seaweed onto the shore.\n",
"seaweed",
"It looks real sticky and wet",
  }));

  set_weather(1, 0, 6);

  set_listen("Even though you are a fair way from the beach you can \n"+
	     "still hear the waves crashing against the rocks below.\n");

  set_smell("You can smell the sea air blowing in from the north.\n");
  set_exits(({
	"d/sorcery/w/angel/path2", "up",
	"d/sorcery/w/angel/dock1", "north",
  }));
}


