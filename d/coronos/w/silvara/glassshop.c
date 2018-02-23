#include <mudlib.h>
inherit STORE;
void reset(status arg) {
    owner = "Stalor";
    if(!present("Stalor")) {
      move_object(clone_object("d/coronos/w/silvara/glassblower"),this_object());
    }
    reset_doors(arg);
    load_door(({
        "destination", "d/coronos/w/alena/ille/g_2",
	"direction", "shop door",
	"long",
	"A large, heavy-set, wooden door.\n",
      }));

    if (arg) return;
    set_short("The House of Glass");
    set_long(
      "\tThe House of Glass.\n"+
      "This is Ille Coronos' only place to have an item of glass made.\n"+
      "Shelves are placed around the shop, full with containers\n"+
      "and other objects of glass.  Behind the counter, is Stalor's the\n"+
      "glassmaker, workroom.  There a blazing fire is kept burning all \n"+
      "day and all night long, just in case a customer needs something\n"+
      "custom made.  A piece of paper hangs from the ceiling over the\n"+
      "counter.\n");

    set_items(({
	"counter",
	"The counter has a wooden frame, but glass sides.  This allows\n"+
	"the shopkeeper to display more expensive glass pieces with\n"+
	"relativly more safety.\n",

	"room#workroom",
	"Behind the counter, one can see and feel the blazing fire used by\n"+
	"the gaffer to create his wares.\n",
	"shelves",
	"Plain shelves made of wood hold glass containers of all shapes\n"+
	"and sizes.\n",
      }));

    set_smell(
      "The smell of burnt wood and smoke comes from the workroom.\n");

    set_listen(
      "The roaring of the fire, as well as an occasional curse, is audible\n"+
      "whenever a piece of glass is shattered.\n");

    set_weather(2,0,0);
    add_sell_items("Glass");
    add_inventory("d/coronos/w/darkness/items/olamp.c");
}
