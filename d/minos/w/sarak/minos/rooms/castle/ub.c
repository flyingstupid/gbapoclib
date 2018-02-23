#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if(!arg) {
      set_short("Under the Evil Prince's Bed");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You are hiding under the evil prince's bed. You seem to be trapped. You can\n"+
"either go back out and fight him or stay under here and wait for him to go\n"+
"back to sleep. Perhaps you should go to sleep while you're waiting.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_exits(({
    CASTLE_ROOMS+"hidden",  "out",
  }));
  set_weather(2,2,0);
  set_items(({
    "bed",  "The bottom of the princes bed is very dirty.",
  }));
 }
}


void init() { 
  ::init();
  add_action("sleep", "sleep"); 
}

status sleep() {
  write ("You close your eyes and go to sleep. When you wake up, you find\n"+
         "yourself in a different place...\n");
  say (this_player()->query_name()+ " goes to sleep and magically drifts away!\n");
  move_object(this_player(), CASTLE_ROOMS+"entrance");
  return 1;
}
    
