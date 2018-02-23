/* MANOR_10.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("Storeroom");
  set_long(
"The small room that you are in is used to store items that the Penors\n"+
"have accumulated over the years, but no longer use. There are several\n"+
"dust covered boxes stacked along the walls of the room. Barrels are\n"+
"scattered everywhere, and all kinds of worthless junk lay strewn all\n"+
"over the floor.\n");

  set_items(({
"wall#walls",
"They are made of wood\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"box#boxes#dust covered box#dust covered boxes",
"Boxes of all sizes are stacked to the ceiling.\n",

"barrel#barrels",
"Sealed barrels of the type used for ale are everywhere.\n",

"junk#worthless junk",
"broken dishes, pictures, toys and all kids of unidentified things\n"+
"all over the place.\n",

           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_9.c", "east",
        "d/coronos/w/nightbringer/manor/manor_6.c", "south",
           }));

}

