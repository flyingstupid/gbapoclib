#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(!arg) {
    set_short("Storm King");
    set_long(
    "You are standing at the bow of the sturdy barque, Storm King. From \n"+
    "here you can see the short foremast. And if you turn around you can \n"+
    "see three large masts. A short ladder takes you back to the lower \n"+
    "parts of the ship. \n");
   set_exits(({
        "players/blake/serios/port",      "port", 
    }));
    set_items(({
        "foremast",   "It looks very strong and seems to be build for hard weather.",
        "ladder", "It seems to be very slippery, be careful.",
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
  


