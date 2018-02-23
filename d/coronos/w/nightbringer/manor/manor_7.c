/* MANOR_7.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("hallway");
  set_long(
"This is a small hallway that branches off in four different directions.\n"+
"It is pretty plain in appearance. There are a few pictures hanging on\n"+
"the walls, but other than that, the hallway is bare.\n");

  set_items(({
"wall#walls",
"They are made of fine wooden paneling\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"picture#pictures",
"There are a few pictures hanging on the walls, they are plain and\n"+
"don't appear to be worth much, as they are dirty and torn in places.\n",

           }));

set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c",  "southeast",
        "d/coronos/w/nightbringer/manor/manor_19.c", "north",
        "d/coronos/w/nightbringer/manor/manor_11.c", "west",
"d/coronos/w/nightbringer/manor/manor_6.c",  "east",
  }));

}

