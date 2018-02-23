/* MANOR_3.C
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  int I;
reset_doors(arg);

  load_door(({
"file", "d/coronos/w/nightbringer/manor/manor_2.c",
     "direction", "north door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));

if(!present("rat")) {
   for(I=0; I<4; I++) {
   move_object(clone_object("d/coronos/w/nightbringer/manor/mon/rat.c"),this_object());
                        }
                           }

if(arg) return;


  set_short("Servants Privy");

set_long(
"This tiny room is very cramped and dingy. It contains only the most \n"+
"primative toilet facilities. There is not even the provisions for \n"+
"washing ones self in here. Mouse droppings and spider webs cover the\n"+
"walls and floor.\n");

  set_items(({
"wall#walls#floor",
"It is made of made of wood\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"toilet#toilet facilities#primative toilet facilities",
"It's actually a large bucket with a wooden seat on top.\n",

"dropping#droppings#mouse droppings#mouse dropping",
"Must I explain? It is mouse droppings.\n",

"web#webs#spider web#spider webs",
"Spiders have wooven their webs on the walls.\n",

            }));

  set_listen("You can hear voices coming from the north\n");

  set_smell("It smells really bad in here...ick.\n");

set_weather(1,2,0);

}
