/* ROOM20
   AUTHOR:NIGHTBRINGER
   05-03-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

if(!present("samantha")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/samantha"),this_object());
}

if(!present("patty")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/patty"),this_object());
}


  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room19",
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
"are painted a plain white. There are stuffed animals all over the room. \n");

  set_items(({
"animals#animal#stuffed animals#stuffed animals",
"Lions and tigers and bears, oh my!",

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

"tables#bedside tables#table#bedside table",
"A small wooden table.",
           }));


  set_weather(1,2,0);

} 

