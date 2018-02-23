/* ROOM39
   AUTHOR:NIGHTBRINGER
   06-1-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("University Dormitory");
  set_long(
     "A long narrow hallway travels forever northward into the\n"+
     "depths of the dormitory. The walls, floor and ceiling are\n"+
     "blackened and shelled out. Burnt wooden doors hang on melted.\n"+
     "hinges. The air feels of an unatural chill. A staircase with\n"+
     "stone steps leads down to the second floor.\n");

  set_items(({
     "stairs#stair#staircase#narrow stairway#stairway",
          "A stairwell of cold grey stone descending downward.",

 "long narrow hallway#narrow hallway#long hallway#hallway#dormitory",
          "Yep, that's where you're at.....",

     "walls#wall",
          "The walls are blackened and burned.",

 "burnt wooden doors#burnt wooden door#wooden doors#wooden door#door#doors",
          "They are burnt and warped. They line the hallway on both/n"+
          "sides, hanging from melted hinges.",

     "ceiling",
          "The ceiling is made out of a cold grey stone that has been\n"+
          "blackened from fire.\n",

     "floor",
          "The floor is made out of a cold grey stone that has beem\n"+
          "blackened by fire.\n",

     "hinge#hinges",
     "Melted black hinges hold the shelled remains of doors upright.\n",
  }));

  set_listen("You can hear strange creaking sounds, accompionied by\n"+
  "mournful wailing and groans.\n");

  set_smell("The air feels smokey and foul.\n");
  set_exits(({
     "d/coronos/w/nightbringer/college/room22", "down",
     "d/coronos/w/nightbringer/college/room40", "north",
       }));
  set_weather(1,2,0);
}

