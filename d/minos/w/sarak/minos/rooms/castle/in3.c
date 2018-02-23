#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

int i;

void reset(status arg) {
  i = 0;
  reset_doors(arg);
  load_door(({
     "file", CASTLE_ROOMS+"in6",
     "direction", "south door",
     "long",
	  "The door has a small window on it.\n",
     "key id", "minotaur key",
     "lock id", "lock",
     "lock description", "The lock glows green\n",
     "closed", "locked",
     "trap on",
     "trap description", 
	  "The trap seems to trigger something.\n",
     "trap damage", (20 + random(15)),
     "trap message", "A spear shoots from the door and hits you"+
		     " in the chest!\n",
      "trap room message", "@@query_name:$this_player()$@@ screams in pain "+
      "as a spear shoots out from\n"+ 
      "the door and through @@query_possessive:$this_player()$@@ chest!\n",
  }));

  i = 0;
  
  if (!present("elite guard")) {
        move_object(clone_object(CASTLE_MONSTERS+"elite"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"elite"), this_object());
  }     
  if (!present("royal guard")) {
    move_object(clone_object(CASTLE_MONSTERS+"royal1"), this_object());
  }  
  
  if(!arg) {
      set_short("Inner Circle of the Castle");
      set_long(

"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"The light here is very bright. The light is coming from a small ciruclar\n"+
"window in the south door. The light is so bright you cannot see in through\n"+
"the window. There are two small statues on either side of the door.This\n"+
"room is heavily guarded.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");  
      set_exits(({
        CASTLE_ROOMS+"in2",  "west",
        CASTLE_ROOMS+"in4",  "east",
        CASTLE_ROOMS+"out7",  "north",
      }));
      set_weather(2,2,0);	
      set_items (({
	"window",  "You cannot see a thing through the window. The light is too bright!",
	"statue#statues", "Which statue would you like to look at?",
	"statue 1#first statue",  "The statue is fixed into the ground and cannot be taken",
        "statue 2#second statue", "This particular statue has a strange "+
                                  "green glow to it. It cannot be taken.\n"+
                                   "However, it looks like you can move the "+
                                   "arm of the statue...",
      }));
  }
}

void init() {
  ::init();
  add_action ("move", "move");
}

status move(string action) {
  string what;

  if (!action) {
    notify_fail("Move What?\n");
    return 0;
  }
  if(!sscanf(action, "arm of %s", what) == 1) {
    notify_fail("Who's arm do you wish to move?\n");
    return 0;
  }

  if (what == "statue 2" || what == "second statue") {
    i++;
    write ("You pull down on the statue's arm. You hear a small click\n"+
	   "and the arm returns to it's original position.\n");
    say (this_player()->query_name()+" pulls the arm of one of the statues.\n");
    if (i == 1) {
      set_door_attribute("south door",  "trap off", 1);
      return 1;
    }
    if (i == 2) return 1;
    if (i == 3) {
      set_door_attribute("south door",  "unlocked", 1);

      return 1;
    }
    if (i == 4) {
      set_door_attribute("south door",  "closed", 1);
      set_door_attribute("south door",  "locked", 1);
      set_door_attribute("south door",  "trap on", 1);
      i = 0;
      say ("Click!\n");
      return 1;
    }  
  }
  else {
    notify_fail("Who's arm do you wish to move?\n"+
	"Statue 1, or statue 2?\n");
    return 0;
  }
} 

