/* ROOM45
   AUTHOR:NIGHTBRINGER
   06-2-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {

  if(arg) return;


  reset_doors(arg);
  load_door(({
    "destination", "d/coronos/w/nightbringer/college/room52",
    "direction", "west door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 1,
  }));


  load_door(({
    "destination", "d/coronos/w/nightbringer/college/room59",
    "direction", "east door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 2,
  }));

  set_short("University Dormitory");
  set_long(
     "A long narrow hallway travels forever northward into the\n"+
     "depths of the dormitory. The walls, floor and ceiling are\n"+
     "blackened and shelled out. Burnt wooden doors hang on melted.\n"+
     "hinges. The air feels of an unatural chill.\n");

  set_items(({
 "long narrow hallway#narrow hallway#long hallway#hallway#dormitory",
          "Yep, that's where you're at.....",

     "walls#wall",
          "The walls are blackened and burned.",

"burnt wooden doors#burnt wooden door#wooden doors#wooden door#doors#door",
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
     "d/coronos/w/nightbringer/college/room44", "south",
       }));
  set_weather(1,2,0);    
}

