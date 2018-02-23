#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;
  int i;

  if(!present("sheep"))
  for(i=0; i<5; i++) {
    ob = clone_object("d/sorcery/w/angel/monst/sheep");
    move_object(ob, this_object());
  }

  if(arg) return;

  set_short("the isle of sorcery");

  set_long(
"A few trees dot the mountain sides here either side of the long, dark\n"+
"basalt path. The air is fresh and clean and the view from here quite \n"+
"spectacular.\n");

  set_items(({
"view",
"You can almost see the whole island shore from here.\n",

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

  set_weather(1, 4, 0);

  set_listen("All is silent up here on the mountain.\n");
  set_smell("The air is crisp and cold.\n");

  set_exits(({
	"d/sorcery/w/angel/path1", "down",
	"d/sorcery/w/angel/path3", "up",
  }));
}


