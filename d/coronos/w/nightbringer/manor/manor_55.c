/* MANOR_55.c
   AUTHOR:NIGHTBRINGER
   04-28-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(1);
  if(arg) return;

  load_door(({
"file", "d/coronos/w/nightbringer/manor/manor_54.c",
    "long", "A trap door in the ceiling",
"direction", "trap door",
  }));


  set_short("Under The Penor's Manor");
  set_long(
"You have found a secret place! But are you sure you wanted to?\n"+
"Erie sounds assault your ears all most instantly, and a damp\n"+
"chill is is the air. It is very dark down here making caution\n"+
"seem a neccissity.\n");


  set_items(({
"wall#walls#floor",
"It is made of made of earth\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

           }));


  set_smell("It smells damp and musty in here.\n");
  set_listen("Erie sounds seem to assail your ears from all directions.\n");

  set_weather(0,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_56.c", "east",
           }));
}

