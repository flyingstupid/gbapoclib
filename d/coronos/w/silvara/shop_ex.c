#include <mudlib.h>
inherit STORE;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file", "d/coronos/w/chi/city/streets/comm6",
      "direction", "shop door",
      "long",
         "A large, heavy-set, wooden door.\n",
      "key id", "domain key",
   }));

   ::reset(arg);
   if(arg) return;
   set_short("the Fine Taylor");
   set_long(
      "\tThe Fine Taylor Outfitters.\n"+
      "You find yourself standing in the middle of Ille Coronos' only\n"+
      "clothing outfitter.  Clothes and accessories of high quality are\n"+
      "made, bought, and sold here.  Behind the wooden counter you see\n"+
      "a storeroom that contains numerous items of clothing and other\n"+
      "accessories.  Hanging from the front of the counter is a small\n"+
      "paper sign.\n"
   );

   set_items(({
         "counter#wooden counter#table#money box#box",
      "The counter is strewn with bits and pieces of multicolored cloth\n"+
      "and string.\n"

         "room#storeroom",
      "Behind the counter you see a massive storeroom that is accessible\n"+
      "only by the owner of the shop.\n",
   }));

   set_smell(
      "The familiar scent of new clothing hangs heavily in the air.\n"
   );
   
   set_listen(
      "All is quiet save the occasional scurrying of a rodent in the\n"+
      "storeroom.\n"
   );   

   set_weather(2,0,0);
   set_owner("Reey");
   add_sell_items("Clothing");
   add_inventory("d/coronos/w/angel/city/obj/wrobe");
   add_inventory("d/coronos/w/angel/city/obj/grobe");
   add_inventory("d/coronos/w/angel/city/obj/brobe");
} 

