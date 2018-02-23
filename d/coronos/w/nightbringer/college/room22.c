/* ROOM22
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
     "line both sides. A narrow stairway made of stone goes down\n"+
     "to the first floor and up to the third floor. The walls of\n"+
     "the stairwell leading up are blackened by what appears to \n"+
     "have been a fire. A icy chill fills the air. The way up is\n"+
     "blocked by a sign.\n");

  set_items(({
     "stairs#stair#staircase#narrow stairway#stairway",
          "A stairwell of cold grey stone descending downward and\n"+
          "ascending up.",

     "stairwell",
     "It leads up to the third floor. The walls have been blackened\n"+
     "by a fire.\n",

     "sign",
     "perhaps you should read it?",

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


  }));

  set_listen("You hear loud voices...\n");
  set_smell("The air here is clean and sterile smelling.\n");
  set_exits(({
     "d/coronos/w/nightbringer/college/room1",  "down",
     "d/coronos/w/nightbringer/college/room23",  "north",
     "d/coronos/w/nightbringer/college/room39",  "up",
       }));
  set_weather(1,2,0);
}


void init() {
  ::init();
  add_action("read", "read");
  add_action("up", "up");
}

status read(string str) {
  if(str == "sign") {
    write(RED_F+"This floor has been placed off limits until further\n"+
    "notice, due to a fire that took the lives of our students.\n"+OFF);

    return 1;
  
  }

  return 0;
}

status up() {
  if((int)this_player()->query_security_level()) {
  tell_object(this_player(), "You're a creator, course you can.\n");
  return 0;
  }

  if ((int)this_player()->query_level() > 19){
  tell_object(this_player(), "You feel brave enough to climb the stairs.\n");
  return 0;
  }

  if((int)this_player()->query_level() < 20){ 
  tell_object(this_player(), "You're too frightened to climb the stairs.\n");
  return 1;
  }
}

