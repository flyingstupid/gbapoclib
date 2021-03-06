#include <mudlib.h>
#include <ansi.h>

inherit PUB;


void reset(status arg) {
  reset_doors(arg);

  if(!present("list")) {
    move_object(clone_object("objects/party_list"),this_object());
  }
  if(!present("bloodeye")) arg = 0;
  /* hack to make bloodeye come back */
  if(arg) return;

  set_exits(({
     "room/city/pub/foyer", "north",
     "room/city/market4",   "west",
  }));

  set_short("Skandle's Downfall");
  set_long(
      "   -=[  Skandle's Downfall  ]=-     \n"+
      "Renamed after the death of an infamous evil wizard who often  \n"+
      "frequented this small shadowy establishment, this pub caters  \n"+
       "for all customers tastes. The long bar is made from black oak,\n"+
      "polished to a high sheen. The light is always kept low and \n"+
      "dim, enhancing the dark shadows that blanket the small booths \n"+
      "around the room. Behind the bar you spot a menu of some sort. \n"+
      "To the north is a small room, with a staircase leading up.   \n");

  set_weather(4,1,0);
  set_owner("bloodeye");

  add_drink("beer", "bottle of beer", "That feels refreshing", 2);
  add_drink("wine", "Glass of fine wine", 
            "A tingling feeling goes through your body", 10);
  add_drink("spirits", "dwarvish spirits", 
            "A shock wave runs through your body", 23);
  add_food("soup", "bowl of vegetable soup", "It tastes like lumpy water", 3);
  add_food("cheese", "cheese", "It smells horrible, but tastes great", 10);
  add_food("bread",  "bread",  "It tasted as lumpy as it looked",18);

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
