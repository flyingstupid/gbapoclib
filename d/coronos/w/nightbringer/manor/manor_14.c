/* MANOR_14.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  int I;

  if(!present("mouse")) {
       for(I=0; I<6; I++) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/mouse.c"),this_object());
                        }
                           }
if(arg) return;

  set_short("stairway");
  set_long(
"This is a long, narrow hallway with a staircase going down. The stairs\n"+
"are wooden and very old and look rickety. It does not appear to be very\n"+
"safe. A cold breeze comes up the stairs..\n");

  set_items(({
"wall#walls",
"They are made of wood\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"stairs#staircase#stair",
"They are old and rickety. The don't look very safe.\n",

           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_11.c",  "east",
"d/coronos/w/nightbringer/manor/manor_54.c",   "down",
  }));

}

