#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if (!present("guard")) {
        move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
  }
  if (!present("elite guard")) {
    move_object(clone_object(CASTLE_MONSTERS+"elite"), this_object());
  }     
 
  if(!arg) {
      set_short("Northern Corridor");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have walked into an extremely bright room. The cause of it seems to be\n"+
"from an intense glow coming from the room south of here. The extra light\n"+
"has highlighted a small part of the wall where someone has scratched a\n"+
"message using some type of sharp object.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");  
      set_exits(({
        CASTLE_ROOMS+"out6",  "west",
        CASTLE_ROOMS+"out8",  "east",
        CASTLE_ROOMS+"in3",  "south",
      }));
      set_weather(2,2,0);
      set_items(({
        "wall",  "There is a small message carved into the wall",
        "message", "You could probably read it if you tried",
      }));
  }
}

void init() {
  ::init();
  add_action("read",  "read");
}

status read (string msg) {
  if (msg == "message") {
    write("The message is a short poem :-\n\n"+
	  "          Once is enough,\n"+
	  "          To save you from pain.\n"+
	  "          But to get straight through,\n"+
	  "          Do it again and again.\n\n"+
	  "          Now be warned,\n"+
	  "          And do not forget.\n"+
	  "          If you do it again,\n"+
          "          There will be much regret!\n\n");
    say (this_player()->query_name()+" reads something on the wall.\n");
    return 1;
  }
  else {
    notify_fail("Read what?\n");
    return 0;
  }
}
