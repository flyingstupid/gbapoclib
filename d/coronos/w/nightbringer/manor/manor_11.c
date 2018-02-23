/* MANOR_11.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  int I;

  if(!present("roach")) {
       for(I=0; I<6; I++) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/roach.c"),this_object());
                        }
if(arg) return;
                           }

  set_short("Hallway");
  set_long(
"This long, narrow hallway stretches off to the west for over fifty feet.\n"+
"Thick padded carpet lines the floor muffling sounds of footsteps. Glass\n"+
"oil lamps are on both sides of the wall at intervals of ten feet.\n");

  set_items(({
"wall#walls",
"They are made of wood\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"carpet#padded carpet#thick padded carpet",
"A thick, deep blue carpet covers the floor. There are several stains on\n"+
"it and it looks to have been burned by something in several spots.\n",

"lamp#oil lamp#lamps#oil lamps",
"Beautiful glass oil lamps are spaced out along both sides of the\n"+
"hall. They are all lit, provided alot of light\n",


           }));


set_weather(2,2,0);
  set_exits(({
       "d/coronos/w/nightbringer/manor/manor_14.c",  "west",
        "d/coronos/w/nightbringer/manor/manor_7.c",   "east",

  }));

}

