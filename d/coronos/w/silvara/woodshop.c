#include <mudlib.h>
//inherit "/players/angel/sys/store";
inherit STORE;
 
void reset(status arg) {
    owner = "Tanthalas";
    if(!present("Tanthalas")){
        move_object(clone_object("/d/coronos/w/silvara/carpenter.c"),this_object());
    }
    reset_doors(arg);
    load_door(({
      "file", "d/coronos/w/alena/ille/g_3",
      "direction", "east door",
      "long",
        "A large, heavy-set, wooden door.\n",
      }));
 
    ::reset(arg);
    if(arg) return;

    set_short("The Hard Knot");
    set_long(
      "\tThe Hard Knot\n"+
      "This is the only wood and furniture shop in Ille Coronos.  Piles\n"+
      "of unfinished wood are stacked neatly on one side of the shop, while\n"+
      "on the other, are finished items to be purchased.  The wooden \n"+
      "counter stands at the back of the store and shines from the oil\n"+
      "the owner lavishly polishes it with.  A beautifully carved sign\n"+
      "is nailed to the front of the counter.\n");
 
    set_items(({
        "counter#wooden counter",
        "A solid oak counter, shining with oil, is covered with\n"+
        "wood shavings and splinters.\n",
        "stacks#stacks of wood#piles#piles of wood",
        "Piles of different kinds of wood lay stacked neatly in the shop.\n",
        "finished items#items#furniture,"
        "Beautiful, finished wooden items are waiting to be purchased.\n",
      }));
 
    set_smell(
      "The smell of pine and cedar hangs in the air.\n");
 
    set_listen(
      "All is quiet save the occasional scampering of a small rodent in \n"+
      "the wood piles.\n");
 
    set_weather(2,0,0);
    add_sell_items("Wooden products");
    add_inventory("d/coronos/w/darkness/items/box1.c");
    add_inventory("d/coronos/w/darkness/items/stick.c");
}
