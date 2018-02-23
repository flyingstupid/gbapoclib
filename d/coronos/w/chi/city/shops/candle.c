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
   set_short("the Enchanted Light");
   set_long(
      "\tThe Enchanted Light Torch & Candle Shoppe.\n"+
      "The scent of wax and sulfer overwhelms your senses as you walk\n"+
      "into the magnificently adorned shop.  On the walls hang various\n"+
      "candles and torches created by a master candle smith.  A little\n"+
      "table sits in the corner where candles and torches are bough.\n"+
      "There is a small wooden sign sitting atop the table.\n"
   );

   set_items(({
         "owner's table#table#covered table#small table#small covered"+
         "table#money box#box",
      "The small covered table is decorated in floral print; no doubt the\n"+
      "work of a female.  On top of the table sits a money box.\n",

         "room#storeroom",
      "Behind the counter you see a massive storeroom that is accessible\n"+
      "only by the owner of the shop.\n",
   }));

   set_smell(
      "Strong floral aromas float in the air and try to cover up the smell\n"+
      "of molten wax.\n"
   );
   
   set_listen(
      "All is quiet save the occasional scurrying of a rodent in the\n"+
      "storeroom.\n"
   );   

   set_weather(2,0,0);
   set_owner("Cirilia");
   set_sell_treasure();
} 

