#include <mudlib.h>
inherit STORE;

void reset(status arg) {
  owner = "Cannon";
  if(!present("Cannon")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/cannon.c"),this_object());
  }
  reset_doors(arg);
  load_door(({
"destination", "d/coronos/w/alena/ille/sk_3",
    "direction", "shop door",
    "long",
    "A large heavy-set wooden door.\n",
  }));
  ::reset (arg);
  if(arg) return;
  set_short("Cannon's Weapons Shop");
  
  set_long(
    "You are standing in the middle of a room with many different\n"+
    "types of weapons hanging from the walls. There is a forge in\n"+
    "the center of the room. There is a wooden sign hanging from\n"+
    "above the door.\n");
    
  set_items
  (({
    "weapons",
      "The weapons are of every different kind.",
    "walls",
      "The weapons are hanging from these walls.",
    "forge",
      "The forge is a deep charcoal color.",
  }));
  
  set_smell(
    "You smell the scent of heated metal.\n"
  );
  
  set_listen(
    "You can hear the sound of metal being hit.\n"
  );
  
  set_weather(2, 0, 0);
  
  
  set_sell_weapon();
}

