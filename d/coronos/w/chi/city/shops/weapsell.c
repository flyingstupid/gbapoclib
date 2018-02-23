#include <mudlib.h>
inherit STORE;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file", "d/coronos/w/chi/city/streets/comm5",
      "direction", "shop door",
      "long",
         "A large, heavy-set, wooden door.\n",
      "key id", "domain key",
   }));

   ::reset(arg);
   if(arg) return;
   set_short("the Armed Citizen");
   set_long(
      "\tThe Armed Citizen Weaponry.\n"+
      "You have just entered the finest weapon shop in the domain of\n"+
      "Ille Coronos.  It is here where warrior both local and foreign\n"+
      "come to update their arsenal in their various personal quests.\n"+
      "In the back corner, behind the owner's table, you see a doorway\n"+
      "that leads into a large room.  You notice a sign hanging from\n"+
      "the table.\n"
   );

   set_items(({
         "owner's table#table#wooden table#sturdy table#sturdy wooden"+
         "table#money box#box",
      "The short wooden table is clear of debis save a money box and\n"+
      "some scraps of metal.\n",

         "room#storeroom",
      "Behind the counter you see a massive storeroom that is accessible\n"+
      "only by the owner of the shop.\n",
   }));

   set_smell(
      "The familar scent of iron ore permeates every nook and crany of\n"+
      "the room.\n"
   );
   
   set_listen(
      "All is quiet save the occasional scurrying of a rodent in the\n"+
      "storeroom.\n"
   );   

   set_weather(2,0,0);
   set_owner("Payton");
   set_sell_weapon();
} 

