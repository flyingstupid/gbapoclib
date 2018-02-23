/* ROOM38
   AUTHOR:NIGHTBRINGER
   05-28-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("University Dormitory");
  set_long(
     "A long narrow hallway travels forever north and south into the\n"+
     "depths of the dormitory. All up and down the hallway, doors\n"+
     "line both sides. The walls and floor are made out of a cold,\n"+
     "grey stone.\n");

  set_items(({
 "long narrow hallway#narrow hallway#long hallway#hallway#dormitory",
          "Yep, that's where you're at.....",

     "walls#wall",
          "The walls are made of a cold grey stone.",

     "stone",
          "The walls, floor, ceiling and stairs are made out of it.",

     "door#doors",
          "They line the hallway on both sides.",

     "ceiling",
          "The ceiling is made out of a cold grey stone.",

     "floor",
          "The floor is made out of a cold grey stone.",

     "plaque",
          "Perhaps you should read it?",

  }));

  set_listen("You hear loud voices...\n");
  set_smell("The air here is clean and sterile smelling.\n");
  set_exits(({
     "d/coronos/w/nightbringer/college/room35",  "south",
     "d/coronos/w/nightbringer/college/room19",  "down",
       }));
  set_weather(1,2,0);
}


