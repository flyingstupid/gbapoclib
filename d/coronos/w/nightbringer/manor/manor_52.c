/* MANOR_52.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
reset_doors(arg);
  if(arg) return;

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_51.c",
     "direction", "east door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));


  set_short("Linen Closet");
  set_long(
"A small closet that has shelves from floor to ceiling. The closet\n"+
"is full of blankets, quilts, sheets, towels, and washclothes. There\n"+
"are some moth balls setting on each shelf\n");

  set_items(({
"wall#walls",
"The walls are plain and rough.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"The floor is made out of rough wooden planks.\n",

"quilt#quilts",
"Several patchwork quilts are on the shelves.\n",

"blanket#blankets",
"Several soft looking blankets are on the shelves.\n",

"sheet#sheets",
"Several white sheets are on the shelves.\n",

"towel#towels",
"Several soft looking towels are on the shelves.\n",

"washcloth#washclothes",
"Several washclothes of various colors are on the shelves.\n",

"shelf#shelves",
"The linen closet has shelves going from floor to ceiling.\n",

"moth ball#moth balls#ball#balls#",
"They are used to keep moths from getting into the linen.\n",

"moth#moths",
"There are no moths here. The moth balls are working.\n",
           }));


  set_weather(2,2,0);

}

