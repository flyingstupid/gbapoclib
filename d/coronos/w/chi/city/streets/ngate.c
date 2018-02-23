#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"

#define MONST   "d/coronos/w/angel/city/monst/"
inherit ROOM;

void reset(status arg) {
   int i;

   if(!present("guard"))
      for(i=0; i<4; i++)
         move_object(clone_object(MONST+"guard1"),this_object());    

   load_door(({
      "destination",      "d/coronos/w/chi/city/streets/ngate",
      "direction",        "north gate",
      "key id",           "domain key",
      "locked",
      "lock difficulty",  1000,
      "lock id",          "padlock",
      "lock description", "The padlock has a rather large keyhole.\n",
      "long",
         "A huge set of large iron gates, standing about 30 feet "+
         "tall\n",
   }));

   if(arg) return;

   set_short(
      "the North Gate of Ille Coronos"
   );

   set_long(
      "\tNorth Gate.\n"+
      "Main street comes to an end here in the north part of Ille\n"+
      "Coronos. A fine road of large stone slabs, carved with\n"+
      "careful hands leads away to the east and west. To the south,\n"+
      "through a vine covered archway, lies the city gardens. The\n"+
      "North Gate is the main defense against possible attacks from\n"+
      "the northern realms and the Drow. "
   );

   set_night_desc(
      "Tall bronzed torch stands\n"+
      "shed light here beside the grand gates.\n"
   );

   set_day_desc("\n");

   set_night_items(({
         "sky#up",
      "You stare up into the star-speckled expanse above you and\n"+
      "contemplate the existence of a benevolent god.\n",

         "tall bronzed torch stands#tall bronzed torch stand#"+
         "bronzed torch stands#bronzed torch stand#torch stands#"+
         "torch stand#torches#torch",
      "Flaming torches illuminate the great iron gates.\n",

         "flame#fire#flames",
      "It looks like the torch is on fire"
   }));

   set_day_items(({
         "sky#up",
      "You look up and are temporarily blinded by the sun.\n",

         "tall bronzed torch stands#tall bronzed torch stand#"+
         "bronzed torch stands#bronzed torch stand#torch stands#"+
         "torch stand#torches#torch",
      "The torches are extinguished at present, but are no doubt\n"+
      "used during the night.\n",
   }));

   set_items(({
         "road#large stone slabs#large stone slab#stone slabs#stone"+
         "slab#stones#stone",
      "A road of large grey stones. It would have taken a whole\n"+
      "army of stone masons to lift this slab into place. It is\n"+        
      "rumoured that dwarves were the architects of this road.\n",

         "archway#vine covered archway",
      "The archway stands at 15 feet tall and is the north entrance\n"+
      "to the city gardens.\n",

         "garden#gardens#city gardens#city garden",
      "You are only able to make out the minutest of details from\n"+
      "where you are standing.\n",
   }));

   set_smell(
      "You breathe deep the scent of a freshly made city.\n"
   );

   set_listen(
      "You hear the monotonous drone of the urban environment.\n"
   );

   set_weather(2,4,0);

   set_exits(({
      "/d/coronos/w/angel/city/gardens/garden1", "south",
      STREETS+"wall10",                          "west",
      STREETS+"wall11",                          "east",
   }));
}

