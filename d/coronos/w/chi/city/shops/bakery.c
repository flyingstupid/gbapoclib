#include <mudlib.h>
inherit PUB;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file",      "d/coronos/w/chi/city/streets/comm9",
      "direction", "bakery door",
      "key id",    "domain key",
      "long",
         "Finely carved and painted, the doors adds a welcoming touch\n"+
         "to the bakery.\n",
   }));

   if(arg) return;

   set_short("Heaven's Bread");
   set_long(
      "\t-=[  Heaven's Bread Bakery  ]=-\n"+
      "You are completely overwhelmed by the enticing aroma of freshly\n"+
      "baked bread.  Behind the counter, sitting in wicker baskets are\n"+
      "loaves of bread that are too numerous to count.  Hanging on the\n"+
      "walls all around you are baskets, floral arrangements, and berry\n"+
      "paintings of many kinds.  There is a sign listing prices hanging\n"+
      "above the many baskets.\n"
   );

   set_items(({
         "bar#names#name#symbol#symbols#wooden bar#oak bar#sturdy bar#"+
         "sturdy oak bar",
      "A sturdy oak bar that has many names and symbols carved into its\n"+
      "surface.  You notice that the menu is carved into the bar as well.\n",
   }));
   set_weather(2,1,0);

   set_smell(
      "Hints of yeast, wheat, and sugar tickle your olfactory senses.\n"
   );

   set_listen(
      "The only thing you can hear are the helpers mixing in the back room.\n"
   );

   set_owner("mowai");

   add_drink("water", "glass of water", 
             "Just the thing to take care of that cotton-mouth", 1);
   add_food("roll", "freshly baked roll",
            "The roll only makes you crave another",12);
   add_food("loaf", "loaf of bread", 
            "The steamy hot bread practically melts in your mouth", 20);
}

