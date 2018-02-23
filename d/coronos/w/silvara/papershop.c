#include <mudlib.h>
inherit STORE;

void reset(status arg) {
    owner = "Gilthea";
    if(!present("Gilthea")) {
	move_object(clone_object("d/coronos/w/silvara/papermaker"),this_object());
    }
    reset_doors(arg);
    load_door(({
        "destination", "d/coronos/w/alena/ille/c_4",
	"direction",   "east door",
	"description",
	"A large, heavy oak door.\n",
      }));

    if(arg)return;
    set_short("The Palace of Papyrus");
    set_long(
      "\The Palace of Papyrus\n"+
      "This papershop is the only place on Ille Coronos to find paper.\n"+
      "Sheets of parchment can be seen stacked neatly in slotted \n"+
      "shelves, while scrolls of many sizes are arranged and sorted\n"+
      "in baskets near the counter.  An unrolled scroll stretches \n"+
      "across the front of the counter listing what the shop has\n"+
      "to offer.\n");

    set_items(({
	"shelves#parchment#sheets",
	"Wooden shelves contain sheets of parchment.\n",
	"baskets#scrolls#scroll",
	"Baskets lay on the floor containing scrolls of many sizes.\n",
	"counter",
	"A wooden counter rests in the back of the shop.\n",
      }));

    set_smell(
      "The pleasant scent of potpourri drifts through the shop.\n");

    set_listen(
      "The only sound is an occasional flipping of pages.\n");

    set_weather(2,0,0);
}
