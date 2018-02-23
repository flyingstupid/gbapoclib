#include <mudlib.h>
#include "/d/ooc/w/jheleg/path.h"
inherit ROOM;

void reset(status arg)
{
   reset_doors(0);
   ::reset(arg);
   if (!arg)
   {
      load_door(({
         "destination", "d/ooc/w/jheleg/bhouse/sand1",
         "direction",   "front door",
         "closed",
         "description",
            "A simple wooden door.\n",
      }));
      set_short("Hallway");
      set_long(
         "  The narrow hallway connects the living room to the rest \n"+
         "  of the house.  The shag carpet contrasts nicely under   \n"+
         "  the soft light provided by the track lighting overhead. \n"+
         "  Hanging on the walls are several pictures of people and \n"+
         "  places that bear some relevance to the locale.  The main\n"+
         "  living area of the beach house is to the east.          \n"
      );
      set_items(({
            "carpet#shag carpet",
         "The pea green shag carpet gives the appearance of a mini     \n"+
         "forest.  You feel for the vacuum that must clean this carpet.\n",

            "track light#track lights#light#lights#track lighting",
         "Three small lights dangle from a track that runs the length of\n"+
         "the hall.  They are bright enough to illuminate the hallway,  \n"+
         "yet soft enough so as to not to contribute to blindness.      \n",


            "picture#pictures#people#places#person#place",
         "Both oil paintings and still life photography are displayed   \n"+
         "along the length of the walls.                                \n",
      }));
      set_smell("The carpet gives off a musty odor.\n");
      set_listen(
         "The echoes of random noises can be heard bouncing off the walls.\n"
      );
      set_ooc_room(1);
      set_weather(2, 2, 0);
      set_exits(({
         BHOUSE "hall2",   "north",
         BHOUSE "livroom", "east",
      }));
   }
}
