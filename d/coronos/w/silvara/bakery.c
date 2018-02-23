#include <mudlib.h>
inherit STORE;

void reset(status arg) {
    owner = "Horratio";
    if(!present("Horratio")) {
	move_object(clone_object("/d/coronos/w/silvara/baker.c"),this_object());
    }
    if(!present("Maddin")) {
	move_object(clone_object("/d/coronos/w/silvara/bakerson.c"),this_object());
    }
    reset_doors(arg);
    load_door(({
        "destination", "d/coronos/w/alena/ille/c_2",
	"direction", "east door",
	"long",
	"A large, heavy-set, wooden door.\n",
      }));
    load_door(({
        "destination", "d/coronos/w/alena/ille/c_13",
	"direction", "back door",
	"long",
	"A large, heavy-set, wooden door.\n",
      }));

    ::reset(arg);
    if (arg) return;
    set_short("Confection Emporium");
    set_long(
      "\tThe Confection Emporium\n"+
      "This is Ille Coronos' only bakery and sweetshop.  Shelves covered\n"+
      "with glass line the shop, allowing customers to eye what sweets and\n"+
      "confections Horratio, the baker, has created to tempt the tastebuds.\n"+
      "One area of the bakery attracts the most attention, for that shelf\n"+
      "only ever contains the famous Chocolate Gnomeclaires, which have even\n"+
      "made kings and queens drool.\n");

    set_items(({
	"shelves#glass shelves",
	"Gazing through the glass, layers of sweets and baked goods\n"+
	"makes one drool.\n",
	"gnomeclaire display case#display",
	"This display case stands in the center of the shop, exhibiting\n"+
	"the famous and delicous Chocolate Gnomeclaire.\n",
      }));

    set_smell(
      "The smell of baked goods and confections waft through the air.\n",
      "The smells of baked goods and confections waft through the air.\n");

    set_listen(
      "The sounds of satisfied customers and of those in anticipation\n"+
      "are a few of the things heard.\n");

    set_weather(2,0,0);
    add_sell_items("Baked goods");
    add_inventory("/d/coronos/w/silvara/muffin.c");
    add_inventory("/d/coronos/w/silvara/drowforestcake.c");
    add_inventory("/d/coronos/w/silvara/gnomeclaire.c");
    add_inventory("/d/coronos/w/silvara/angelcookie.c");

}
