#include <mudlib.h>
#include "paths.h"
inherit ROOM;
 
void reset(status arg) {
   if(!arg) {
     set_short("Forest entrance");
     set_long(
  "A long trail winds its way to the northwest to the forest known \n"+
  "as Scianthian. The road that leads to the fertile farming lands \n"+
  "of the northeast meanders to a pleasent looking, little farm.   \n");
      set_exits(({
         "/d/coronos/w/newstar/newbie/rooms/path1", "northeast",
	PATH+"new1", "northwest",
	PATH+"road1", "south",
       }));
       set_weather(2,4,3);
    }
}
