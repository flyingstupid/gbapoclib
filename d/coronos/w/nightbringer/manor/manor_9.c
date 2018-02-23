/* MANOR_9.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
int I;
  if(!present("guard")) {
       for(I=0; I<8; I++) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/guard.c"),this_object());
                        }
                           }

if(arg) return;

  set_short("House Guard Billets");
  set_long(
"This large room is used for billeting the Penors' house guards. Eight\n"+
"cots are arranged in an orderly fashion, with a footlocker at the foot.\n"+
"of each cot. The room is devoid of any decorations as it is just used for\n"+
"the guards to sleep in after finishing their twelve hour shifts\n");

  set_items(({
"wall#walls",
"They are made of wood\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"cot#cots",
"It is a small, plain cot. It doesn't look very comfortable.\n",

"locker#lockers#foot locker#foot lockers",
"It is a wooden chest used to store belongings in.\n",
           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_5.c", "south",
        "d/coronos/w/nightbringer/manor/manor_10.c", "west",
           }));

}

