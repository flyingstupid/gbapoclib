/* MANOR_50.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
reset_doors(arg);

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_53.c",
     "direction", "south door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));
if(arg) return;


  set_short("Washroom");
  set_long(
"A small chamber that is simply decorated. There is a copper bathtub and\n"+
"a simple toilet. The walls are painted a sky blue, and someone has used \n"+
"a feather duster to dip into pink paint and make designs on the wall.\n");

  set_items(({
"wall#walls",
"They are made of wood and painted sky blue with pink designs.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out of wooden planks.\n",

"bathtub#tub#copper bathtub",
"It is about five feet long and made of copper. A small water\n"+
"pump is at the edge of the tub to use in filling it.\n",

"toilet",
"It is basically a bucket with a wooden seat on top. It has to\n"+
"be carried out and dumped.\n",

"small water pump#water pump#pump",
"A water pump brings water in from the outside.\n",
           }));


  set_weather(2,2,0);

}

