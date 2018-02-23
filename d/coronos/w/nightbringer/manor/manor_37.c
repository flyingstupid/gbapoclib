/* MANOR_37.C
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_36.c",
     "direction", "east door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));

  if(!present("spider")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/spider.c"),this_object());
       }
  if(arg) return;

set_short("Guests Chamber");
set_long(
"The guest room is immaculate, and designed with good taste. A peach\n"+
"colored carpet covers the floor and the walls are painted a pale blue.\n"+
"There is a featherbed with a small bedside table along the west wall.\n"+
"A large rolltop desks is in the nothwest corner of the room and a \n"+
"chest of drawers is in the northeast corner. A chamber pot sets beside\n"+
"the bed\n");

  set_items(({
"wall#walls",
"They are made of wood and painted a pale blue\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is covered with a peach colored carpet.\n",

"bed#featherbed",
"A featherbed with a handsome quilt and a fluffy pillow. It looks quite\n"+
"comfortable.\n",

"table#bedside table#small bedside table",
"It is made out of oak wood and has a dwawer that can hold items.\n",

"desk#rolltop desk#large rolltop desk",
"A large rolltop desks made out of oak, it has many drawers.\n",

"chest#chest of drawers#chest of drawer",
"A massive dresser that has several drawers to store clothes in\n",

"pot#chamber pot",
"This is used by the guest at night to relieve themselves without having\n"+
"to go down stairs\n",

"quilt#handsome quilt",
"A patchwork quilt covers the small bed\n",

"pillow#fluffy pillow",
"A fluffy white pillow lays at the head of the bed.",

"carpet#peach colored carpet",
"A peach colored carpet covers the floor.\n",

           }));


  set_weather(2,2,0);

}

