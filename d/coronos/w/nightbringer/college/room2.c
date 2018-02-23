/* ROOM2
   AUTHOR:NIGHTBRINGER
   05-02-97 */

#include <mudlib.h>
inherit PUB;


void reset(status arg) {
  if(arg) return;


    set_short("The Diner");
   set_long(
      "   -=[  Ma Kettle's  ]=-     \n"+
"Named for Ma Kettle, the dormitory supervisor. This diner caters to\n"+
"the students of Ille Coronos University who live here. There is a \n"+
"long bar made from a beutiful redwood, polished to a high sheen. The\n"+
"lighting is dim, enhancing relaxation from a long day of studies. Small\n"+
"booths set along the walls of the room, filled with students catching a\n"+
"quick bite and a drink. Behind the bar you spot a menu of some sort.\n");

  set_weather(2,2,0);
  set_owner("Ma Kettle");
  add_drink("coffee","Cup of Coffee", "That feels good", 2);
  add_drink("tea",   "Glass of Tea", "Ahh, that hit the spot.",10);
  add_drink("jolt",  "Jolt", "What a rush!",23);
  add_food("soup", "bowl of Vegetable Soup", "As it goes down it tastes like lumpy water",3);
  add_food("cheese", "cheese", "It smells horrible, but tastes great", 10);
  add_food("bread",  "bread",  "It tasted as lumpy as it looked",18);

 set_items(({
    "bar#long bar",
        "A long thin bar of redwood.",

    "light#lights#lighting",
        "It is dim.",

    "Small booths#small booth#booths#booth",
        "Small booths line the walls. Students are sitting in them.",

    "student#students",
        "Several students are sitting in the booths.",
}));

  set_exits(({
     "d/coronos/w/nightbringer/college/room1", "east",
  }));
  set_weather(1,4,0);

}

void init() {
  ::init();
  add_action("set", "set");
}

status set(string str) {
  if(str == "booth") {
    write("You set in the booth\n");
    return 1;
  }
  return 0;
}


