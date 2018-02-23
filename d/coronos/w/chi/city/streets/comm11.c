#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"

inherit ROOM;

void reset(status arg) {
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
      STREETS+"comm10", "northeast",
      STREETS+"comm12", "southwest",
   }));
}
