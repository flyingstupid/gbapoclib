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
         "destination", "d/ooc/w/jheleg/bhouse/hall1",
         "direction",   "front door",
         "closed",
         "description",
            "A simple wooden door.\n",
      }));

      set_short("Sandy Path");
      set_long(
         " You stand on a sandy path that ends in on the front doorsteps of\n"+
         " a rather lonely looking beach house.  The exterior of the house \n"+
         " looks as though it could use some paint, but other than that, it\n"+
         " it is your typical beach cottage.                               \n"
      );
      set_ooc_room(1);
      set_weather(2, 4, 0);
      set_smell("The air reeks of salt.\n");
      set_listen("The seagulls gawk as they fly high overhead.\n");
      set_exits(({
         BHOUSE "sand2", "south",      
      }));
   }
}

