/* MANOR_25.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
if(arg) return;

  load_door(({
    "destination", "d/coronos/w/nightbringer/manor/manor_26.c",
    "direction", "north door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 1,
  }));

  load_door(({
    "destination", "d/coronos/w/nightbringer/manor/manor_17.c",
    "direction", "south door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 2,
  }));

  set_short("Hallway");
  set_long(
"A dark hallway leading to the servants areas of the manor. The floor is\n"+
"wooden and cold and the walls are bare. There is a door on both sides of\n"+
"the hallway. The Penors obviously didn't waste any money on decoration\n"+
"in this portion of the manor.\n");

  set_items(({
"wall#walls",
"They are made out wood.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is made out of rough wood and is cold.\n",

           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_23.c",  "east",
        "d/coronos/w/nightbringer/manor/manor_27.c",  "west",
  }));

}

