/* MANOR_6.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;


  set_short("hallway");
  set_long(
"This is a small hallway that branches off in four different directions.\n"+
"It is pretty plain in appearance, the only decoration at all is a large\n"+
"statue setting in the middle of the room.\n");

  set_items(({
"wall#walls",
"They are made of fine wooden paneling\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"statue#large statue",
"It is a large statue made from marble. It is a likeness of Lord Penor.\n",
           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c",  "south",
        "d/coronos/w/nightbringer/manor/manor_7.c",  "west",
        "d/coronos/w/nightbringer/manor/manor_10.c", "north",
        "d/coronos/w/nightbringer/manor/manor_5.c",  "east",
           }));

}

