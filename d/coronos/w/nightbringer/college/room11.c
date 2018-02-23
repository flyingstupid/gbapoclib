/* ROOM11
   AUTHOR:NIGHTBRINGER
   05-03-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

if(!present("ashley")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/ashley"),this_object());
}

if(!present("amanada")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/amanda"),this_object());
}


  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room10",
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
"are painted a plain white. There is a small sign over one of the beds. \n");

  set_items(({
"sign#small sign",
"It simply says: I LOVE GAVIN!, in big letters.\n",

"wall#walls",
"They are made of wood and painted a plain white color.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is made out of hardwood.\n",

"beds#small beds#bed#small bed",
"A featherbed with a handsome quilt and a fluffy pillow. It looks quite\n"+
"comfortable.\n",

"dresser#dressers",
"A massive dresser that has several drawers to store clothes in\n",

"quilt#handsome quilt",
"A patchwork quilt covers the small bed\n",

"pillow#fluffy pillow",
"A fluffy white pillow lays at the head of the bed.",

"tables#bedsidetables#table#bedside table",
"A small wooden table.",
           }));


   set_weather(1,2,0);

} 

