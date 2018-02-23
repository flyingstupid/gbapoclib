/* ROOM19
   AUTHOR:NIGHTBRINGER
   05-2-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {

  if(arg) return;


  reset_doors(arg);
  load_door(({
    "destination", "d/coronos/w/nightbringer/college/room20",
    "direction", "west door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 1,
  }));


  load_door(({
    "destination", "d/coronos/w/nightbringer/college/room21",
    "direction", "east door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 2,
  }));


  set_short("University Dormitory");
  set_long(
     "A long narrow hallway travels forever southward into the\n"+
     "depths of the dormitory. All up and down the hallway, doors\n"+
     "line both sides. A narrow stairway made of stone goes up.\n"+
     "There is a plaque on the east and west doors.\n");

  set_items(({
     "stairs#stair#staircase#narrow stairway#stairway",
          "A stairwell of cold grey stone ascending upward.",


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
     "d/coronos/w/nightbringer/college/room16",  "south",
     "d/coronos/w/nightbringer/college/room38",  "up",

       }));
  set_weather(1,4,0);    
}


void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(str == "plaque on west door") {
    write(RED_F+"-+= 112 [SAMANTHA STRONG/PATTY DUKE] =+-\n"+OFF);

    return 1;
  
  }
  if(str == "plaque on east door") {
    write(RED_F+"-+= 111 [SANDRA THOMAS/HEATHER BULLOCK] =+-\n"+OFF);

    return 1;
  }

  if(str == "plaque") {
    write("read plaque on east door or read plaque on west door?\n");

    return 1;
  }
  return 0;
}

