#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

int i;

void reset(status arg) {
  i = 0;
  if (!present("guard")) {
     move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
     move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
  }     
 
  if(!arg) {
    set_short("Southwest Corner of the Castle");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have found the southwest corner of the castle. This room is not as\n"+
"bright as the other rooms in the castle. The light provided from the\n"+
"chandeliers doesn't seem to be as bright. Perhaps there is something\n"+
"wrong with them...\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");  
    set_exits(({
      CASTLE_ROOMS+"out1",  "east",
      CASTLE_ROOMS+"out3",  "north",
    }));
    set_weather(2,2,0);
    set_items(({
      "light#chandeliers#chandelier",
        "As you gaze up at the chandeliers, you notice that one of\n"+
			    "them is not working. One of the gold chains supporting them\n"+
			    "has fallen and broken one of the candles.",
      "chain",  "The chain is hanging from the chandelier. You may be able\n"+
		"to reach it if you jump high enough!",
      "portrait#portraits#picture#pictures",
	  "The pictures are of various members of minotaur\n"+
	  "castle. The have all been framed in gold\n",
      "floor#tiles",  "The tiles on the floor have been made up of rich white opals",
    }));
  }
}

void init() {
  ::init();
  add_action("jump",  "jump");
}

status jump() {
  if (i >= 1) {
    write ("As you prepare to jump, you notice that someone else has beaten you to it.\n");
    return 1;
  }
  if (this_player()->query_strength() > 10) {
    write ("You jump with all your might. At the height of your jump, you reach\n"+
	   "out and snatch the gold chain from the chandelier!\n");
    say (this_player()->query_name()+" jumps high into the air and snatches something\n"+
	 "hanging from the chandelier!\n");
    i++;
    move_object(clone_object(CASTLE_ITEMS+"chain"), this_object());
    return 1;
  }
  else {
    write ("You jump with all your might but cannot quite reach the chain.\n"+
	   "Perhaps if you were a bit stronger...\n");
    say (this_player()->query_name()+ " jump up and snatches at the air.\n");
    return 1;
  }
  return 0;
}
