#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(!arg) {
    set_short("Sea Wind");
    set_long(
    "This is a little sloop designed for only a small number of passangers. \n"+
    "The boat is in quite good shape but all the tools and other things \n"+
    "seems dirty and slightly used. In the stern you can see a flag with \n"+
    "the name Sea Wind on. \n");
   set_exits(({
        "players/blake/pyramid/corr03",  "out",
    }));
    set_items(({
        "flag",   "The flag is white with the text Sea Wind written in red on it.",
    }));
    set_weather(1,4,6);
 }
 
}
void room_message() {
   tell_room(this_object(), "The waves are beating on the hull.\n");
   call_out("room_message", 15);
}
void init() {
   ::init();
   call_out("room_message", 15);
}

