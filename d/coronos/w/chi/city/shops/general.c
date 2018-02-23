#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"
inherit "inherit/store2";

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file", "d/coronos/w/chi/city/streets/comm7",
      "direction", "shop door",
      "long",
         "A large, heavy-set, wooden door.\n",
      "key id", "domain key",
   }));

   ::reset(arg);

   set_storeroom(SHOPS +"storeroom");
   clean_store();
   set_store_items( 3, OBJ+"fat");
   set_store_items( 3, OBJ+"ore");
   set_store_items( 3, "objects/bag");

   if(arg) return;
   set_short("the Hole in the Wall");
   set_long(
      "\tHole in the Wall General Store.\n"+
      "It is here that people can find miscellaneous items from all around\n"+
      "the realm.  Numerous rows of shelves line the wall behind the long\n"+
      "wooden counter and proudly display the bounties of the shop.  A \n"+
      "fireplace takes up much of the opposite wall and exists for decoration\n"+
      "only.  Hanging by two chains from the ceiling is an iron sign.\n"
   );

   set_items(({
         "counter#long wooden counter#wooden counter#long counter",
      "The counter is kept clean by the owner; no doubt a ploy to keep\n"+
      "her customers coming back.\n",

         "shelves#shelf#rows of shelves#row of shelves#bounties#items#item",
      "Thin wooden shelves are attached firmly to the wall so as to not\n"+
      "collapse under the weight of the items that sit upon them.\n",

         "fireplace#opposite wall",
      "A large stone fireplace sits quietly on the opposite wall.  Lack\n"+
      "of soot tells you that it is not used much, whether by lack of\n"+
      "need or lack of want.\n",
 
         "chains#chain",
      "Two linked chains support the weight of the largish iron sign that\n"+
      "bears instructions for the shop.\n",         
   }));

   set_smell(
      "A most welcoming potpourri has been set out for your smelling pleasure.\n"
   );
   
   set_listen(
      "Every now and then you hear the faint whistle of wind escaping from the\n"+
      "outside through the fireplace.\n"
   );   

   set_weather(2,0,0);
   set_owner("len");
} 

