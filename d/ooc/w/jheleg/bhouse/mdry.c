#include <mudlib.h>
#include "/d/ooc/w/jheleg/path.h"
inherit ROOM;

void reset(status arg)
{
   reset_doors(0);
   ::reset(arg);

   if(!arg)
   {
      load_door(({
         "destination", "d/ooc/w/jheleg/bhouse/laundry",
         "direction",   "round door",
         "closed",
         "description",
            "It is a small, round, and made of aluminum.\n",
      }));

      set_short("Inside the Clothes Dryer");
      set_long(
         "  A spacious cavern known as a giant clothes dryer envelopes you \n"+
         "  completely.  Offering enough room for countless peoples, you \n"+
         "  are quite comfortable here.                                  \n"
      );
      set_smell("A freshly washed scent floats by your nose.\n");
      set_listen(
         "Your breathing echoes off of the cylindrical chamber of the\n"+
         "chamber.\n"
      );
      set_weather(2, 1, 0);
   }
}

