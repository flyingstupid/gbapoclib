#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(!arg) {
    set_short("a large boat");
    set_long(
    "This is the sterncastle of the Storm King. A flag with some strange \n"+
    "symbols are hanging over the sea. A great rigging stretches out towards \n"+
    "the top of the main mast. Everything is very clean and in perfect shape.\n");
   set_exits(({
           "players/blake/serios/port",      "port", 
    }));
    set_items(({
        "flag",   "On the blue flag you can see a strong man with a golden trident in his hand",
        "rigging", "Its some kind of net used by the sailors",
    }));
    set_weather(2,4,3);
 }
}
void room_message() {
   tell_room(this_object(), "The boat rocks gently in the wind.\n");
   call_out("room_message", 15);
}
void init() {
   ::init();
   call_out("room_message", 15);
}


