#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"

inherit ROOM;

void reset(status arg) {
   if(arg) return;

   set_short(
      "Wall Street"
   );

   set_long(
      "\tWall Street.\n"+
      "You are at the westernmost extremity of Wall Street.  From\n"+
      "here, your only alternatives are to go continue south along\n"+
      "West Road, or to track east along Wall Street towards the\n"+
      "North Gate of Ille Coronos.  "
   );

   set_night_desc(
      "The shadows are playing with\n"+
      "your mind here as you are thinking that you are seeing\n"+
      "shapes darting from bush to bush.\n"
   );

   set_day_desc("\n");

   set_night_items(({
         "sky#up",
      "You stare up into the star-speckled expanse above you and\n"+
      "contemplate the existence of a benevolent god.\n",
   }));

   set_day_items(({
         "sky#up",
      "You look up and are temporarily blinded by the sun.\n",
   }));

   set_items(({
         "road#wall street#street",
      "The road is of average construction at this location mostly\n"+
      "due to the fact that its creators did not see it being used\n"+
      "much.\n"
   }));

   set_smell(
      "You breathe deep the scent of a freshly made city.\n"
   );

   set_listen(
      "It is deathly quiet.\n"
   );

   set_weather(1,4,0);

   set_exits(({
      STREETS+"wall2", "east",
      STREETS+"west1", "south",
   }));
}

