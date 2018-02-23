#include <mudlib.h>
inherit STORE;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file", "d/coronos/w/chi/city/streets/comm14",
      "direction", "shop door",
      "long",
         "A large, heavy-set, wooden door.\n",
      "key id", "domain key",
   }));

   ::reset(arg);
   if(arg) return;
   set_short("the Resource of the Realms");
   set_long(
      "\tResource of the Realms Cartography.\n"+
      "Ille Coronos, being such a large town, and all of its neighboring areas\n"+
      "have been documented carefully upon their exploration.  This quaint shop\n"+
      "bears the fruit of those explorations for a meager price.  Large carefully\n"+
      "drawn maps adorn the walls and you catch glimpses of places unknown, sacred,\n"+
      "and even unexplored.  A sign stands proundly in the middle of the room.\n"
   );

   set_items(({
         "wall#walls#map#maps",
      "The walls proudly display the efforts of many a successful expedition.\n",
   }));

   set_smell(
      "You notice nothing out of the ordinary.\n"
   );
   
   set_listen(
      "You hear nothing out of the ordinary.\n"
   );   

   set_weather(2,0,0);
   set_owner("Apiya");
   set_sell_treasure();
} 

