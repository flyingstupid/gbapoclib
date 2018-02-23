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
         "destination", "d/ooc/w/alena/main/porch1",
         "direction",   "screen door",
         "closed",
         "description",
            "A silver mesh screen door.\n",
      }));

      set_short("Sandy Path");
      set_long(
         " You stand at the beginning of a sandy path that continues for a\n"+
         " ways to the north.  Allowing entrance into a quite large beach \n"+
         " condominium is a mesh screen door.  You can't tell much about  \n"+
         " the house from the outside as it is fairly featureless.  Much  \n"+
         " awaits you on the inside, however.                             \n"
      );
      set_ooc_room(1);
      set_weather(2, 4, 0);
      set_smell("The air reeks of salt.\n");
      set_listen("The seagulls gawk as they fly high overhead.\n");
      set_exits(({
         BHOUSE "sand1", "north",      
      }));
   }
}

