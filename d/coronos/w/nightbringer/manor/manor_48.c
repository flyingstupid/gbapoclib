/* MANOR_48.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_47.c",
     "direction", "west door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));

  if(!present("drake")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/drake.c"),this_object());
       }
  if(arg) return;

  set_short("Drake's Room");
  set_long(
"The typical room of a ten year old boy, toy swords, axes, knifes and\n"+
"soilders lay scattered all over the floor, the room is quite the mess.\n"+
"There is a small bed, a chest of drawers and a chamber pot.\n");

  set_items(({
"wall#walls",
"They are made of wood and painted a pale blue\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is covered with a blue colored carpet.\n",

"bed#small bed",
"A featherbed with a handsome quilt and a fluffy pillow. It looks quite\n"+
"comfortable.\n",


"sword#swords",
"Wooden swords of all sizes lay on the floor.\n",

"axe#axes",
"Wooden axes of all shapes and sizes lay on the floor.\n",

"knife#knives",
"Wooden daggers and knives lay on the floor.\n",

"soilder#soilders",
"Bunches of small carved wooden soilders lay scattered all over the floor.\n",

"chest#chest of drawer#chest of drawers\
#drawers#drawer",
"A massive dresser that has several drawers to store clothes in\n",

"pot#chamber pot",
"This is used by the guest at night to relieve themselves without having\n"+
"to go down stairs\n",

"quilt#handsome quilt",
"A patchwork quilt covers the small bed\n",

"pillow#fluffy pillow",
"A fluffy white pillow lays at the head of the bed.",

"carpet",
"A blue carpet covers the floor",

           }));


  set_weather(2,2,0);

}

