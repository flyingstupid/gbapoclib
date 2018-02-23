#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

int z;

void reset(status arg) {
  int i, j;
  z = 0;
  if (!present("servant")) {
    i = random(100);
    if (i < 50) {
      j = 1;
      i = random(3) + 1;
      while (j <= i) {
        move_object(clone_object(CASTLE_MONSTERS+"servant"), this_object());
	j++;
      }
    }
  }     
 
  if(!arg) {
    set_short("Eastern Corridor");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"The eastern corridor is extremely bright. There are the usual portraits,\n"+
"gold chandeliers and opaline tiles. There are sometimes servants standing\n"+
"in the corridor chatting on their breaks. There is something slightly\n"+
"different about this room but can't quite work it out...\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    set_exits(({
      CASTLE_ROOMS+"out10",  "north",
      CASTLE_ROOMS+"out12",  "south",
    }));
    set_weather(2,2,0);
    set_items(({
      "portraits#portrait#picture#pictures",
	  "The pictures are of various members of minotaur castle\n"+
	  "One of the frames has broken and a piece of it is just\n"+
	  "hanging there. It could easily be snapped off.",
      "floor#tiles",  "The tiles on the floor have been made from rich white opals",
        "light#chandeliers#chandelier",
          "The chandeliers provide light for the room",
    }));  
  }
}

void init() {
  ::init();
  add_action("snap",  "snap");
}

status snap(string frame){
  if (z >= 1) {
    write ("It is gone!!\n");
    return 1;
  }
  if (frame == "frame") {
    write ("You snap off the frame and take it with you.\n");
    say(this_player()->query_name()+" snaps something off a portrait and slips it into "+
	this_player()->query_possessive()+" pocket.\n");
    move_object(clone_object(CASTLE_ITEMS+"frame"), this_player());
    z++;
    return 1;
  }
  return 0;
}
