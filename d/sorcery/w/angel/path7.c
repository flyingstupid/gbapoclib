#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);

  load_door(({
	"file", "d/sorcery/w/angel/pub",
	"direction", "south door",
	"long",
	"A strong and sturdy door\n",
  }));

  if(arg) return;
  set_short("the isle of sorcery");

  set_long(
"The long basalt road comes to and end here in a neat clutter of \n"+
"small houses. To the north comes the smell of baking bread, while\n"+
"to the south you can hear laughter and merriment.");
  set_night_desc(
						      " The lights from\n"+
"the houses shed a little light into the street.\n");
  set_day_desc("\n");

  set_night_items(({
"light",
	"The lights from the houses shine into the street",
  }));

  set_items(({
"houses#small houses",
"They have grown up to serve the wizards who gather in the tower",
  }));


  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/path5", "east",
  }));

  set_listen("You can hear the clink of glasses to the north.\n");
  set_smell(
"Your tummy starts to rumble as your senses are met by \n"+
"the delicious smells of freshly baked goods.\n");
}

