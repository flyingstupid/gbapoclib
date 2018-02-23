/* MANOR_46.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_45.c",
     "direction", "west door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));

  if(!present("jessica")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/jessica.c"),this_object());
       }
  if(arg) return;

set_short("Jessicas Room");
  set_long(
"The typical room of a six year old girl, a dollhouse and several dolls\n"+
"set neatly in one corner of the room. A small desk with a pad of paper\n"+
"and a large box of crayons set beside a small bed. There is a chest of\n"+
"drawers and a champer pot.\n");

  set_items(({
"wall#walls",
"They are made of wood and painted a pale pink\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is covered with a peach colored carpet.\n",

"bed",
"A featherbed with a handsome quilt and a fluffy pillow. It looks quite\n"+
"comfortable.\n",

"house#dollhouse",
"A three foot tall dollhouse, accurate in detail is in the southwest corner.\n"+
"of the room.\n",

"doll#dolls",
"A family od dolls lay beside the dollhouse.\n",

"chest#chest of drawers#chest of drawer",
"A massive dresser that has several drawers to store clothes in\n",

"pot#chamber pot",
"This is used by the guest at night to relieve themselves without having\n"+
"to go down stairs\n",

"quilt#handsome quilt",
"A patchwork quilt covers the small bed\n",

"pillow#fluffy pillow",
"A fluffy white pillow lays at the head of the bed.",

"desk#small desk", "A small childs desk that is used to color on. There\n"+
"is a pad of paper and a box of crayons on it.\n",

"paper#pad of paper",
"A pad of paper that has been colored on. It is a picture of a clown.\n",

"crayons#crayon#box of crayons#box of crayon#small box of crayons\
#small box#box",
"A large box of crayons sets on the desk, there must be at least one hundred\n"+
"colors here, most of them have been broken in at least two pieces.\n",


           }));


  set_weather(2,2,0);

}

