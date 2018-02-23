/* ROOM53
   AUTHOR:NIGHTBRINGER
   06-02-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room39",
     "direction", "west door",
     "long",
          "A plain wooden door.\n",
     "open",
     "door number", 1,

  }));


  set_short("Dormatory Room");
  set_long(
"Somehow, this room has been spared the devastaing effects of the\n"+
"fire that has ravaged the rest of this floor. Two small beds lay\n"+
"peacefully on either side of the room, with a small bedside table\n"+
"beside each. Two dressers seperate the beds.\n");

  set_items(({
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

