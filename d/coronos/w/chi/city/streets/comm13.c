#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"

inherit ROOM;

void reset(status arg) {
   reset_doors(0);
   load_door(({
      "destination",      "d/coronos/w/chi/city/shops/armbuy",
      "direction",        "northeast door",
      "key id",           "domain key",
      "unlocked",
      "long",
         "A solid, heavy-set, wooden door.\n",
   }));

   if(arg) return;

   set_short("Commerce Street");

   set_long(
      "\tCommerce Street.\n"+
      "Here is where the wares of peoples near and far are sold, bought,\n"+
      "and traded for.\n"
   );

   set_smell(
      "The smell of "
   );

   set_listen(
      "The clanging of metal upon metal and the voices merchants can be\n"+
      "heard all throughout this part of town.\n"
   );

   set_weather(1,4,0);

   set_exits(({
      STREETS+"comm12", "northwest",
      STREETS+"comm14", "southeast",
   }));
}
