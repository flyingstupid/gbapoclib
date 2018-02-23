/* ROOM8
   AUTHOR:NIGHTBRINGER
   05-03-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

if(!present("toni")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/toni"),this_object());
}

if(!present("alicia")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/alicia"),this_object());
}


  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room7",
     "direction", "east door",
     "long",
          "A plain wooden door.\n",
     "closed",
     "door number", 1,

  }));


  set_short("Dormatory Room");
  set_long(
"This is a small cramped room. It contains two small beds, two bedside\n"+
"tables, and two dressers. The floor is made from hardwood and the walls\n"+
"are painted a plain white. The room is pretty plain, with the only \n"+
"decoration being a small tapestry hanging on the wall.\n");

  set_items(({
"small tapestry#tapestry",
"It depicts a scene of young revelers having a good time.\n",

"wall#walls",
"They are made of wood and painted a plain white color.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is made out of hardwood.\n",

"bed#beds#small bed#small beds",
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

