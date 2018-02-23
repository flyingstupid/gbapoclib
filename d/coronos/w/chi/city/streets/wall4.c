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
      "Along the northern wall of the city you find much that is\n"+
      "left to be desired.  The road in poor condition, the shrubs\n"+
      "unkept, and the wall itself already showing signs of neglect,\n"+
      "you are unsure that it is even safe to be walking along here.\n"+
      "To the east you see an intersection of streets.\n"
   );

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
      "much.\n",

         "wall#northern wall#north wall",
      "The wall stands at around 30 feet tall and is constructed of\n"+
      "giant stone slabs.  Although recently built, the wall is\n"+
      "showing some signs of wear.\n",

         "shrubs#shrub",
      "The shurbs have been allowed to grow unchecked here.  They\n"+
      "have more than doubled their size in height and in bulk.\n",
   }));

   set_smell(
      "You breathe deep the scent of a freshly made city.\n"
   );

   set_listen(
      "It is deathly quiet.\n"
   );

   set_weather(1,4,0);

   set_exits(({
      STREETS+"wall3", "west",
      STREETS+"wall5", "east",
   }));
}

