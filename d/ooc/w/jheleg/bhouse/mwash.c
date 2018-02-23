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

      set_short("Inside the Washing Machine");
      set_long(
         "  You find yourself inside a large washing machine.  It appears a\n"+
         "  lot larger than it does from the outside.                      \n"
      );
      set_smell("The strong scent of laundry detergent hangs in the air.\n");
      set_listen(
         "Your breathing echoes off of the cylindrical chamber of the\n"+
         "chamber.\n"
      );
      set_weather(2, 1, 0);
   }
}

