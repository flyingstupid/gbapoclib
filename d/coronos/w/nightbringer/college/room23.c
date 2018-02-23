/* ROOM23
   AUTHOR:NIGHTBRINGER
   05-6-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {

  if(arg) return;



  set_short("University Dormitory");
  set_long(
     "A long narrow hallway travels forever northward into the\n"+
     "depths of the dormitory. All up and down the hallway, doors\n"+
     "line both sides. The walls and floor are made out of a cold,\n"+
     "grey stone. Someone has defaced the wall with grafitti here.\n");

  set_items(({
 "long narrow hallway#long hallway#narrow hallway#hallway#dormitory",
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

     "grafitti",
          "Perhaps you should read it?",

  }));

  set_listen("You hear loud voices...\n");
  set_smell("The air here is clean and sterile smelling.\n");
  set_exits(({
     "d/coronos/w/nightbringer/college/room22",  "south",
     "d/coronos/w/nightbringer/college/room26", "north",

       }));
  set_weather(1,2,0);
}


void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(str == "grafitti") {
    write(RED_F+"-+= NightBringer Rulez ! =+-\n"+OFF);

    return 1;
  
  }

  return 0;
}

