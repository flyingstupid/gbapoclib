/* MANOR_59.c
   AUTHOR:NIGHTBRINGER
   04-28-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("Under The Penor's Manor");
  set_long(
"The starange wailing sounds increase in volume a dramatically as you\n"+
"head south. If you are looking for the source of the wailings, it\n"+
"appears that you are heading in the right direction, if the sounds.\n"+
"can be trusted.\n");


  set_items(({
"wall#walls#floor",
"It is made of made of earth\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

           }));


  set_smell("It smells damp and musty in here.\n");
  set_listen("Erie sounds seem to assail your ears from all directions.\n");

  set_weather(0,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_60.c", "south",
        "d/coronos/w/nightbringer/manor/manor_57.c", "north",
           }));
}

