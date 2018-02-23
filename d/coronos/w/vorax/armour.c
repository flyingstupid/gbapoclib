#include <mudlib.h>
inherit STORE;

void reset(status arg) {
  owner = "Denon";
  if(!present("Denon")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/denon.c"),this_object());
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
  set_short("Denon's Armoury");
  
  set_long(
    "You are standing in the middle of a room with many pieces of\n"+
    "armour strung about all over the walls. In the middle of the\n"+
    "floor is a large steel forge. Toward the back wall you can\n"+
    "see the storeroom that contains many types of armour waiting\n"+
    "to be sold. There is a sign here hanging above the door.\n");
  
  set_items
  (({
    "armour",
      "The armour is strung about everywhere, and is stacked in\n"
      "great piles inside the storeroom.\n",
    "large steel forge#large forge#steel forge#forge",
      "The steel forge is being used to make armour.\n",
    "room#storeroom",
      "The storeroom is closed to all but the owner of the shop.\n",
  }));
  
  set_smell(
    "The smell of iron is very heavy in the air.\n"
  );
  
  set_listen(
    "The sounds of metal being hit is heard from somewhere.\n"
  );
  
  set_weather(2,0,0);
  set_sell_armour();
}

