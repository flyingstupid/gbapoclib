#include <mudlib.h>
inherit STORE;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file", "d/coronos/w/chi/city/streets/comm12",
      "direction", "shop door",
      "long",
         "A large, heavy-set, wooden door.\n",
      "key id", "domain key",
   }));

   ::reset(arg);
   if(arg) return;
   set_short("the Bountiful Harvester");
   set_long(
      "\tThe Bountiful Harvester.\n"+
      "Wheat, being Ille Coronos' main crop, is a much needed resource\n"+
      "for it's townfolk.  It is here that people can buy and sell wheat\n"+
      "to either make bread or to make a profit.  It is rather cool in\n"+
      "here due to the temperature needed to keep the wheat fresh.  Thick\n"+
      "stone walls surround you with little to nothing on them to look at.\n"+
      "On the far side of the room, over a little table, hangs a sign.\n"
   );

   set_items(({
         "stone walls#stone wall#walls#wall#thick stone walls#thick stone wall#"+
         "thick walls#thick wall",
      "Grey featureless walls surround you on all sides.  They are cold to the\n"+
      "touch; it is for this reason that they were picked for the construction\n"+
      "of this shop.\n",

         "table#little table",
      "A small frail table sits in the corner solely for the purpose of allowing\n"+
      "the owner to make transactions.\n",      
   }));

   set_smell(
      "A musty smell hangs heavily in the air.\n"
   );
   
   set_listen(
      "All is quiet save the occasional scurrying of a rodent in the\n"+
      "storeroom.\n"
   );   

   set_weather(2,0,0);
   set_owner("Quoniah");
   set_sell_treasure();
} 

