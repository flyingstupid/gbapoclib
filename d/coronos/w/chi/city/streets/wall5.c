#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"

inherit ROOM;

void reset(status arg) {
   if(arg) return;

   set_short(
      "Intersection of Wall Street and Slant Street"
   );

   set_long(
      "\tWall Street.\n"+
      "There is a small intersection here that joins Wall Street\n"+
      "and Slant Street which runs off to the southwest.  Though\n"+
      "not as bas as to the west, the quality of the roads and of\n"+
      "the North Wall is slightly below average here.  The closer\n"+
      "you get to the North Gate, the more lively your surroundings\n"+
      "seem.\n"
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

         "intersection",
      "The intersection of Wall Street and Slant Street has been\n"+
      "virtually usused as there is no real reason for the majority\n"+
      "of the population to venture out to this part of the city.\n",
   }));

   set_smell(
      "You breathe deep the scent of a freshly made city.\n"
   );

   set_listen(
      "It is deathly quiet.\n"
   );

   set_weather(1,4,0);

   set_exits(({
      STREETS+"wall4",  "west",
      STREETS+"wall6",  "east",
      STREETS+"slant1", "southwest",
   }));
}

