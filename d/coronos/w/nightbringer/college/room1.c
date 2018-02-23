/* ROOM1
   AUTHOR:NIGHTBRINGER
   05-2-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;


reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/darkness/dormpath",
     "direction", "dorm door",
     "long",
          "A ornately carved wooden door.\n",
     "closed",
     "door number", 1,

  }));

  set_short("University Dormitory");
  set_long(
     "A long narrow hallway travels forever northward into the\n"+
     "depths of the dormitory. All up and down the hallway, doors\n"+
     "line both sides. A narrow stairway made of stone goes up.\n"+
     "There is a sign here.\n");

  set_items(({
     "stairs#stair#staircase#narrow stairway#stairway",
          "A stairwell of cold grey stone ascending upward.",

     "hall#hallway#dormitory",
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

     "sign",
          "Perhaps you should read it?",

  }));

  set_listen("You hear loud voices...\n");
  set_smell("The air here is clean and sterile smelling.\n");
  set_exits(({
     "d/coronos/w/nightbringer/college/room22",  "up",
     "d/coronos/w/nightbringer/college/room4",  "north",

       }));
  set_weather(1,2,0);    
}


void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(str == "sign") {
    write(GREEN_F+"    -+= Dormitory rules and regulations. =+-\n"+OFF+
YELLOW_F+
"1. Boys are on the second floor.\n"+
"2. Girls are on the first floor.\n"+
"3. Boys are to remain on the second floor after 9pm.\n"+
"4. You too girls, after 9pm, remain on the first floor.\n"+
"5. Everyone must be in by 10pm! NO EXECPTIONS!!!!\n"+OFF);

    return 1;
  }
  return 0;
}

