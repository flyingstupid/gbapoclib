#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(0);
  if(!arg) {
    set_short("Storm King");
    set_long(
    "You have entered a sturdy barque named Storm King. In difference \n"+
    "from other boats you notice that this one seems to be very clean \n"+
    "and in very good shape. The owner seems to be a perfectionist. \n"+
    "A mighty main mast rises towards the sky. You can see hooks \n"+
    "on the mast that probably use to hold some lanterns at night.\n");
   set_exits(({
        "players/blake/pyramid/corr03",   "out",
        "players/blake/serios/stern",     "stern",
        "players/blake/serios/bow",       "bow",
    }));
    set_items(({
        "mast#main mast",
            "The mast is really high ",
        "hooks", "They look very sturdy.",
    }));
    load_door(({
      "destination", "players/blake/serios/bel_deck",
      "description", "The large hatch swings easy on its well oiled hinges.\n",
      "key id", "no_key",
"direction",  "hatch"
      "closed"
}));
    set_weather(2,4,3)
 
void room_message() {
  tell_room(this_object(), "The boat rocks gently in the wind.\n");
  call_out("room_message", 15);
}
void init() {
  ::init();
  call_out("room_message", 15);
}
