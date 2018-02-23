#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(0);
  if(!arg) {
    set_short("Storm King");
    set_long(
    "Barrels are piled up in straight rows along both sides of the hull. \n"+
    "Further on you can see eight large crates and a number of chests. As \n"+
    "you turn around you see a heap of sacks probably containing grain. \n"+
    "Even here in the darkness everything is clean and in good shape. \n"+
    " \n");
   set_items(({
        "barrels#barrel", "They are piled up along both sides of the hull.",
        "crates#crate",   "They are all empty.",
        "chests#chest",   "The chests are made of sturdy wood and looks very heavy.",
        "sacks#sack",     "They are all filled with grain.",
    }));
    load_door(({
      "destination", "players/blake/serios/port",
      "description", "The large hatch swings easy on its well oiled hinges.\n",
      "key id", "no_key",
      "direction", "hatch",
      "closed",
    }));

    set_weather(00,2,0)
 
void room_message() {
  tell_room(this_object(), "You hear the waves gurgle against the hull. \n");
  call_out("room_message", 15);
}
void init () {
  ::init();
  call_out("room_message", 15);
}
