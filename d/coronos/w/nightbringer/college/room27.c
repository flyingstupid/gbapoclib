/* ROOM27
   AUTHOR:NIGHTBRINGER
   05-29-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

if(!present("otik")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/otik"),this_object());
}

if(!present("steel")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/steel"),this_object());
}


  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room26",
     "direction", "east door",
     "long",
          "A plain wooden door.\n",
     "open",
     "door number", 1,

  }));


  set_short("Dormatory Room");
  set_long(
"This is a small cramped room. It contains two small beds, two bedside\n"+
"tables, and two dressers. The floor is made from hardwood and the walls\n"+
"are painted a plain white. There is a pinup poster on the wall and an \n"+
"empty keg of ale is in the corner.\n");

  set_items(({
"pinup poster#pinup#poster",
"It's a poster of a beautiful girl.\n",

"empty keg#keg",
"It used to hold ale, but it's all been drank.\n",

"corner",
"It is the place where two walls meet. There's an empty keg in one of them.\n",

"wall#walls",
"They are made of wood and painted a plain white color.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is made out of hardwood.\n",

"bed#small bed#beds#small beds",
"A featherbed with a handsome quilt and a fluffy pillow. It looks quite\n"+
"comfortable.\n",

"dresser#dressers",
"A massive dresser that has several drawers to store clothes in\n",

"quilt#handsome quilt",
"A patchwork quilt covers the small bed\n",

"pillow#fluffy pillow",
"A fluffy white pillow lays at the head of the bed.",

"table#bedside table#tables#bedside tables",
"A small wooden table.",
           }));


  set_weather(1,2,0);

} 

