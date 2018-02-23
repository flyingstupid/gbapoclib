/* MANOR_16.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
reset_doors(arg);


  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_23.c",
     "direction", "north door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));
if(arg) return;

  set_short("Servants quarters");
  set_long(
"A small room with the bare minimum of furnishings. The Penors provide\n"+
"their servants with a room to live in, and not much more. There is a \n"+
"small bed, a stool, and a bedside table in here.\n");

  set_items(({
"wall#walls",
"They are made of wood\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out of wooden planks.\n",

"small bed#bed",
"A simple bed made by sewing two sheets together and stuffing them\n"+
"straw. There is a battered looking pillow and a ragged quilt on\n"+
"the bed.\n",

"stool",
"A small wooden stool that can be used to set on, though it\n"+
"look like it would be comfortable.\n",

"table#bedside table",
"It is made from cheap wood and has a dwawer that can hold items.\n",

           }));


set_weather(2,2,0);

}

