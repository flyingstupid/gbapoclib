#include <mudlib.h>
inherit STORE;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file", "d/coronos/w/chi/city/streets/comm3",
      "direction", "shop door",
      "long",
         "A large, heavy-set, wooden door.\n",
      "key id", "domain key",
   }));

   ::reset(arg);
   if(arg) return;
   set_short("the Armoured Pawn");
   set_long(
      "\tThe Armoured Pawn Armoury.\n"+
      "Being Ille Coronos' principle armoury, it is here that peoples\n"+
      "from near far come to buy, sell, and trade their different pieces\n"+
      "of armour.  Behind the long porous stone counter, you see a room\n"+
      "that contains rack upon rack of merchandise.  You notice a sign\n"+
      "that sits at the far end of the counter.\n"
   );

   set_items(({
         "long porous stone counter#porous stone counter#stone counter#"+
         "long stone counter#stone counter#counter",
      "Spanning the distance of the room, the counter serves as a place\n"+
      "of bartering for the different customers that come here.\n",

         "room#storeroom",
      "Behind the counter you see a massive storeroom that is accessible\n"+
      "only by the owner of the shop.\n",
   }));

   set_smell(
      "The familar scent of iron ore and leather permeate every nook and\n"+
      "crany of the room.\n"
   );
   
   set_listen(
      "All is quiet save the occasional scurrying of a rodent in the\n"+
      "storeroom.\n"
   );   

   set_weather(2,0,0);
   set_owner("Greston");
   set_sell_armour();
} 

