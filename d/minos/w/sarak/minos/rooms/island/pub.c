#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"

inherit PUB;


void reset(status arg) {

  if(!present("prithirian")) arg = 0;
  if(arg) return;

  set_exits(({
    ISLAND_ROOMS+"west1",  "up",
  }));

  set_short("Minotaur's Revolt");
  set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"     The Minotaur's Revolt\n"+
"You find yourself in a strange underground cavern. The room seems to have\n"+
"been dug out totally by hand. The walls, floor and ceiling are perfectly\n"+
"straight. There is no way this room could have occurred naturally. Sitting\n"+
"on an old wooden bench is a small menu.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_weather(2,2,0);
  set_owner("prithirian");
  set_items(({
    "floor#wall#walls#roof#ceiling",
      "It's perfectly smooth. Unlike anything you've ever seen",
    "bench",
      "There is a menu on it.",
  }));

  add_drink("draught", "This bottle of draught is stronger than normal beer",
    "Ahhh! That's better!", 5);
  add_drink("hammerhead", "It's a mixture of anything Prithirian could find",
    "You see where the drink gets its name. You're head really hurts now", 18);
  add_drink("bourbon", "Minotaur's Special Bourban",
    "A burning sensation rushes back up your throat", 30);
  add_food("soup", "A nice bowl of Leprechaun Soup.",
    "Suprisingly, the Leprechauns have a great taste!", 7);
  add_food("pickles", "The pickles have benn collected from the forest",
    "They taste awful, but you feel a lot better.", 15);
  add_food("damper", "This doughy substance is similar to bread.",
    "Very nice!", 23);

}
