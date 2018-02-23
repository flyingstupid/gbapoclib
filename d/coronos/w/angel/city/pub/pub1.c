#include <mudlib.h>
#include <ansi.h>

inherit PUB;


void reset(status arg) {
  reset_doors(arg);

  if(!present("list")) {
    move_object(clone_object("objects/party_list"),this_object());
  }
  load_door(({
	"destination", "d/coronos/w/alena/ille/m_3",
	"direction",   "south door",
	"long",
		"A fine door made from oak.\n",
  }));

  if(arg) return;


  set_short("the Griffon Inn");
  set_long(
" -[ the Griffon Inn ]- \n"+
"A fine long counter, made from a dark red oak, reaches out toward the \n"+
"dark corner where a fire sits waiting to be lit. Several tables sit   \n"+
"around the room, from which shady figures gaze at you through the dim \n"+
"candle light. On the back wall, behind the counter, is a menu.\n");

  set_weather(4,1,0);
  set_owner("Ferris");

  add_sdrink("water", "bottle of water", "That was a bit muddy", 1);
  add_sdrink("milk", "bottle of milk", "Straight from the cow ..and just as warm", 3);
  add_drink("ale",  "bottle of ale",  "That was quite refreshing", 1);
  add_drink("mead", "pint of mead", "That quenched your thirst!", 8);
  add_drink("draught", "draught of beer", "A burning feeling races through "+
	"your brain", 15);
  add_drink("wine", "orange weed wine", "It tastes as bad as it smelt!", 20);
  add_drink("minotaur ale", "a pint of minotaur ale",
	    "You now know why only Minotaurs drink it", 30);
  add_food("broth", "bowl of broth", "It is a little watery", 2);
  add_food("bread", "stale bread", "That wasn't very tasty", 3);
  add_food("chicken", "some chicken", "A little dry for your tastes", 5);


  set_items(({
	"stairs#stair#staircase#up",
	"In the next room you can see a staircase leading to "+
	"rooms on the next floor",
    "bar",        "A long thin bar of black oak",
  }));

}

void init() {
  ::init();
  add_action("read","read");
}

status read(string str) {
  if(str=="list") {
    write("The fonts on the list are too small to read from here. You should get it\n"+
    "before you can read it.\n");
    return 1;
  }
  return 0;
}
