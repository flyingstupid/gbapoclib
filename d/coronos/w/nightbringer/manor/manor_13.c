/* MANOR_13.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  int I;
reset_doors(arg);

  load_door(({
"file", "d/coronos/w/nightbringer/manor/manor_12.c",
     "direction", "east door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));

  if(!present("mouse")) {
       for(I=0; I<6; I++) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/mouse.c"),this_object());
                        }
if(arg) return;
                           }

  set_short("Pantry");
  set_long(
"You are in a good sized pantry. Shelves filled with dry food stuffs\n"+
"cover all of the walls. There is some spilled rice and flour on the\n"+
"floor.\n");

  set_items(({
"wall#walls",
"They are made out of wood that has been painted white.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is made out of wood.\n",

"shelf#shelves",
"Long wooden shelves filled to overflowing with food line the walls of\n"+
"the pantry\n",

"dry food#food",
"Sacks of flour and sugar, fresh fruits and veggies, and a large \n"+
"assortment of spices and seasonings are placed on the shelves\n",

"rice#flour",

"Something has chewed the bottom of a few sacks and caused the contents\n"+
"to spill out onto the floor.\n",

           }));


set_weather(2,2,0);

}

