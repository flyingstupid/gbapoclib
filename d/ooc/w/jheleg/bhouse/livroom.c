#include <mudlib.h>
#include "/d/ooc/w/jheleg/path.h"
inherit ROOM;

void reset(status arg)
{
   ::reset(arg);
   if (!arg)
   {
      set_short("Living Room");
      set_long(
         "  The living room of the beach house is a rather laid \n"+
         "  back room where people can take a break from their  \n"+
         "  ventures in the sand and sun.  Many pictures of     \n"+
         "  various sea-scapes adorn the walls along with random\n"+
         "  relics from the sea itself.  A huge window overlooks\n"+
         "  the emerald waters of the ocean.                    \n"
      );
      set_items(({
            "picture#pictures#paintings#painting#oil painting#"+
            "oil paintings",
         "Old gruffy men are shown in various environments      \n"+
         "battling the elements of the harsh aquatic realms.    \n"+
         "Other pictures portray lazy summer days on the beach  \n"+
         "with friends and family.                              \n",

            "wall#walls",
         "Several oil paintings of various themes hang perfectly\n"+
         "on the walls.  In the corners and around the pictures \n"+
         "are displayed artifacts that have been extracted from \n"+
         "the sea itself.                                       \n",

            "relic#relics#artifact#artifacts#fishing nets#fishing "+
            "net#starfish#dried starfish#shell#shells#swordfish#"+
            "giant swordfish#fish",
         "Old and brittle fishing nets occupy the wall space that     \n"+
         "is not covered by the pictures.  Dried starfish, shells     \n"+
         "of various sizes, and a giant swordfish are also on display.\n",
      }));
      set_smell("The stale smell of salts hangs in the air.\n");
      set_listen(
         "You can barely hear the crash of the tides against the shore\n"+
         "from within the house.\n"
      );
      set_ooc_room(1);
      set_weather(2, 2, 0);
      set_exits(({
         BHOUSE "hall1", "west",
      }));
   }
}

