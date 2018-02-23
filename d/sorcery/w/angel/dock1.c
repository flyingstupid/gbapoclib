#include <mudlib.h>
inherit ROOM;

object ob;
void reset(status arg) {
  object ob;
  int i;

  if(!present("callin")) {
    if(ob) return;
    ob = clone_object("d/sorcery/w/angel/monst/callin");
    move_object(ob, this_object());
  }

  if(!present("sea gull")) {
    for(i=0; i<5; i++) {
      ob = clone_object("d/sorcery/w/angel/monst/gul");
      move_object(ob, this_object());
    }
  }

  /* this is to make the sea turtle make its way here */
  if(arg) return;

  set_short("the isle of sorcery");

  set_long(
"A long stone platform extends outward toward the horizon, standing out \n"+
"of the ocean waiting patiently for ships to dock. A small bell hanging \n"+
"from a brass support and pole sways slowly in the breeze, every now and\n"+
"again letting out a soft chime. Toward the south the dock ends in a    \n"+
"long walkway of basalt, winding upward toward some mountains.          \n");

  set_items(({
"moutains#mountain",
"There is something at its peak, but you can't tell what it is from here",
"walkway#path",
"It's made from a dark rock, and is a patchwork of triangular shapes",

"bell",
"A small brass bell. It still looks in good condition.\n",
"support#brass support",
"A long pole, possibly fashioned in a human forge.\n"+
"It supports a single brass bell.\n",

"platform#dock",
"A long dock for ships travelling to the Isle of Sorcery to dock. From the\n"+
"lack of seafaring amenities it looks as though few ships come by here",

"ocean#wave#waves#sea",
"The waves crash against the beach, washing some seaweed onto the shore.\n",
"seaweed",
"It looks real sticky and wet",

  }));

  set_weather(1, 0, 6);
  set_listen("The waves crash against the beach\n");
  set_smell("Salt is strong in the sea breeze that stings your nostrels.\n");
  set_exits(({
	"d/sorcery/w/angel/path1", "south",
	"d/affils/ships/open/types/turtle/stern", "sea turtle",
  }));
}

void init() {
  ::init();
  add_action("ring", "ring");
}

status ring() {
  write("The bell lets out a soft chime.\n");
  say(this_player()->query_name()+" rings the bell on the dock.\n");
  return 1;
}

