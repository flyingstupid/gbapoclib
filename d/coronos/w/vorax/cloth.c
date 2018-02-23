#include <mudlib.h>
inherit STORE;

void reset(status arg) {
  owner = "Sarah";
  if(!present("Sarah")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/sarah.c"),this_object());
  }
    reset_doors(arg);
    load_door(({
"destination", "d/coronos/w/alena/ille/c_10",
  "direction", "shop door",
  "long",
  "A large, heavy-set, wooden door.\n",
      }));
    ::reset(arg);
    if(arg) return;
    set_short("Sarah's Cloth Shop");
    set_long(
      "You find yourself standing in the middle of Ille Coronos'\n"+
      "cloth shop. Cloth of high quality is made here. There is a\n"+
      "wooden counter in the corner of the room with some pieces\n"+
      "of cloth laying on it.  There is a wooden sign hanging from\n"+
      "above the doorway.\n");

    set_items(({
	"wooden counter#counter",
	"The counter has samples of the cloth you may buy here.",
	"cloth",
	"There is silk, and cotton, and rayon cloth here.",
	"silk#silk cloth",
	"The silk cloth is very soft and smooth.",
	"cotton#cotton cloth",
	"The cotton cloth is very durable.",
	"rayon#rayon cloth",
	"The rayon cloth is fairly soft, and fairly durable.",
      }));

    set_weather(2,0,0);
    add_sell_items("Cloth");
    add_inventory("/d/coronos/w/vorax/items/silk.c");
    add_inventory("/d/coronos/w/vorax/items/cloth.c");
    add_inventory("/d/coronos/w/vorax/items/rayon.c");
}
