#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

#define SERVANTS        3

object *servants;

void reset(status arg) {
  object serv;
  int i;

  if(!servants) servants = allocate(SERVANTS);
  for(i = 0; i < 3 ; i++) {
    if(!servants[i]) {
      serv = clone_object(CASTLE_MONSTERS+"servant");
      servants[i] = serv;
      move_object(servants[i], this_object());
    }
  }

  if(arg) return;

  set_short("Castle Entrance");
  set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have entered the Minotaur's castle. The whole area is bright with the\n"+
"glittering of gold. Gold chandeliers hang from the ceiling providing the\n"+
"room with a brilliant gold glow. The floor has been tiled with a strange\n"+
"white gem and the walls have portraits of various people on them. This\n"+
"small room would be a perfect place to greet visitors of the castle.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_exits(({
    CASTLE_ROOMS+"valley",  "south",
    CASTLE_ROOMS+"out1",  "west",
    CASTLE_ROOMS+"out13",  "east",
    CASTLE_ROOMS+"in5",  "northeast",
    CASTLE_ROOMS+"in1",  "northwest",
  }));
  set_weather(2,2,0);
  set_items(({
       "light#chandeliers#chandelier",
        "The chandeliers provide light for the room",
    "floor#tiles", "The tiles on the floor have been made from rich, white opals",
    "portraits#portrait#picture#pictures", 
      "The pictures are of various members of the minotaur castle.\n"+
      "They are all surrounded by a rich, gold frame. The second\n"+
      "picture catches your eye",
    "second picture#picture 2#portrait 2#second protrait#",
      "The picture is of a young minotaur wearing a crown. The eyes\n"+
      "have been cut out to provide a peep hole. Unfotunately, these\n"+
      "type of holes work both ways. Perhaps if you peeped through the\n"+ 
      "eyes you will see more. You also notice a small lever on the\n"+
      "side of the frame",
    "lever",  "Perhaps if you were to pull it...",
  }));
}
 
void init() {
  ::init();
  add_action("pull", "pull");
  add_action("peep", "peep");

}

status peep(string cmd){
  if (!cmd) {
    write ("peep through?\n");
    return 1;
  }
  if (cmd == "through") {
    write ("peep through what??\n");
    return 1;
  }

  if ((cmd == "through holes") || (cmd == "through hole") ||
    (cmd == "through eyes")) {
    if (find_living("radagast")) {
      write ("You peep through the holes and see someone sleeping on a"+
             " bed inside.\n");
    }
    else {
      write ("You peep through the holes but see only an empty room.\n");
    }
    say (this_player()->query_name()+ " peeps through a hole in the painting.\n");
    return 1;
  }
  return 0;
}

status pull(string lev) {
  if (lev == "lever") {
    say (this_player()->query_name()+" does something to one of the pictures."+
                                      " The wall\n"+
	 "spins around and "+this_player()->query_name()+" is gone!!\n");
    write ("You pull the lever. A grinding noise comes from within the walls as\n"+
	   "they begin to move! The whole wall turns around taking you with it!!\n"+
	   "You are thrown to the ground as the wall stops abruptly to turn back\n"+
           "to it's original position. ");
    if (find_living("radagast")) {
      write ("The sounds of the wall moving have\n"+
             "woken the evil prince sleeping here. He is NOT impressed!!\n");
    }
    else write ("Fortunately, no one is here.\n");
    this_player()->move_player("mysteriously#"+CASTLE_ROOMS+"hidden");
    return 1;
  }
  return 0;
}
