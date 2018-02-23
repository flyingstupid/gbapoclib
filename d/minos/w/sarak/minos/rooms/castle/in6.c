#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

int i;

void reset(status arg) {
  i = 0;
  reset_doors(arg);
  load_door(({
     "file", CASTLE_ROOMS+"in3",
     "direction", "north door",
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

  if (!present("royal guard")) {
        move_object(clone_object(CASTLE_MONSTERS+"royal"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"royal"), this_object());
  }     
 
 if(!arg) {
      set_short("The Inner Sanctum");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have found your way into what the Minotaurs call the Inner Sanctum.\n"+
"The room is bare except for two statues placed on either side of the door.\n"+
"The blinding light is still very intense here. It definately orginated in\n"+
"the room south of here. You sense great evil coming from there.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"in3",  "north",
        CASTLE_ROOMS+"in7",  "south",
      })); 
      set_weather(2,2,0);
      set_items(({
	"window",  "You can see through the window, but on the other side, you can't",
        "statue#statues",  "Which statue would you like to look at?",
        "statue 1#first statue", "The statue is fixed into the ground and "+
                                 "cannot be taken",
         "statue 2#second statue", "This particular statue has a strange "+
                                   "green glow to it. It cannot be taken.\n"+
           "However, it looks like you can move the arm of this statue...\n",
      }));
      

  }
}

void init () {
  ::init ();
  add_action("move", "move");
}

status move (string action) {
  string what;
  if (!action) {
    notify_fail("Move what?\n");
    return 0;
  }
// Was only using "arm of", while "arm on" seems acceptable and was attempted by a player.
// Altered by Vaejor - 02/13/2002
  if (action[0..5] == "arm of" || action[0..5] == "arm on") {
    what = action[6..];
    if (what[0] == ' ')  what = what[1..];
  } else {
    notify_fail("Who's arm do you wish to move?\n");
    return 0;
  }

  if (what == "statue 2" || what == "second statue") {
    i++;
    write ("You pull down on the statue's arm. You hear a small click\n"+
           "and the arm returns to it's original position.\n");
    say (this_player()->query_name()+" pulls the arm of one of the statues.\n");
    if (i == 1) {
      set_door_attribute("north door", "trap off", 1);
      return 1;
    }
    if (i == 2) return 1;
    if (i == 3) {
      set_door_attribute("north door", "unlocked", 1);
      return 1;
    }
    if (i == 4) {
      set_door_attribute("north door", "closed", 1);
      set_door_attribute("north door", "locked", 1);
      set_door_attribute("north door", "trap on", 1);
      i = 0;
      say ("Click!\n");
      return 1;
    }
  }
  else {
    notify_fail("Who's arm do you wish to move?\n");
    return 0;
  }
}
