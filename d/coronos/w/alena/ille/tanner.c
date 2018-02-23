#include <mudlib.h>
inherit STORE;

void reset(status arg) {
    reset_doors(arg);
    load_door(({
"destination", "d/coronos/w/alena/ille/c_11",
	"direction", "east door",
	"long",
	"A large, heavy-set, wooden door.\n",
      }));
    ::reset(arg);
    if(!arg) {
	set_short("the Leather Binder");
	set_long(
	  "\tLeather Binder - Maker of Fine Leather Goods.                     \n"+
	  "Famed for the quality and intricate designs that it produces,       \n"+
	  "the Leather Binder has served the Ille Coronos area for as long     \n"+
	  "as the eldest elf can remember.  The dimly lit shoppe is quite      \n"+
	  "bare save a few stools and some miscellaneous leather goods hanging \n"+
	  "behind the long wooden counter.  A bold sign hangs loosly from the  \n"+
	  "countertop.                                                         \n"
	);
	
	set_items(({
	    "counter#wooden counter#long wooden counter",
	    "The counter is littered with strips of unused leather.\n",

	    "stool#stools",
	    "Randomly placed all over the shoppe are stools that have been roughly\n"+
	    "carved from unwanted wood.  It would be in your best interest to leave\n"+
	    "them as they are; unoccupied.\n"+

	    "miscellaneous leather goods#leather goods",
	    "Worth nothing to the customer, yet priceless to the crafter, meaningless\n"+
	    "pices of crafted, shaped, engraved, and dyed leather hang from behind\n"+
	    "the counter.\n",
	    
	    "room#storeroom",
	    "Behind the counter you see a massive storeroom that is accessible\n"+
	    "only by the owner of the shop.\n",
	  }));
	
	set_smell(
	  "The shoppe reeks of soaking leather.\n"
	);
	
	set_listen(
	  "All is quiet save the occasional scurrying of a rodent in the\n"+
	  "storeroom.\n"
	);   
	
	set_weather(2,0,0);
	set_owner("Kord");
	add_sell_items("Clothing");
  add_inventory("/d/coronos/w/darkness/items/tan/belt.c");
  add_inventory("/objects/quiver");
  add_inventory("/d/coronos/w/angel/city/obj/hat");
  add_inventory("/d/coronos/w/darkness/items/tan/pouch.c");
  add_inventory("/d/coronos/w/darkness/items/tan/vest.c");
    }
} 
/* Coded by Jheleg */
/* Stolen by Alena *chuckle* */
