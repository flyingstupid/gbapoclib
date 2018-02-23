#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/gardens/"
inherit ROOM;

status climb();
void reset(status arg) {
  if(arg) return;

  set_short("the city garden");
  set_long(
     "Walking through the bushland garden gives you a sence of peace  \n"+
     "you have never felt before. Perhaps this is why so many come to \n"+
     "visit the Ille Coronos city gardens. Either side of the cobblestone   \n"+
     "path stand large ghost-gums. ");
  set_day_desc(
     "The sunlight beams down on you from\non high, peaking through "+
     "the white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as dark \nsinister clouds pass by.\n");

  set_listen("The wind rustles in the gum trees around you.\n");
  set_smell("There is the strong smell of eucalyptus here.\n");

  set_items(({
     "path#cobblestone path#cobblestones#cobblestone",
          "A well travelled cobblestone path",
     "tree#gum tree#ghost-gum#gum",
          "This tree's trunk is a light grey, almost white colour. Atop \n"+
          "the tree is some movement amid the leaves",
     "leaves#leaf#movement",
          "You can't quite see from here. Perhaps you'll have to climb up?",
  }));
  set_day_items(({
     "sunlight#sun#light",
          "Do you want to go blind?",
     "cloud#clouds",
          "They are white and fluffy. One reminds you of a big koala",
  }));
  set_night_items(({
     "moon",
          "A white barron moon",
     "cloud#clouds",
          "They look dark and sinister...and very spooky",
  }));
  set_exits(({
	PATH+"garden4", "north",
	PATH+"garden12", "south",
	PATH+"garden9", "east",
	PATH+"garden7", "west",
  }));
  set_weather(1,4,0);
}

void init() {
  ::init();
  add_action("climb", "climb");
  add_action("climb", "up");
}

status climb() {
  write("You carefully climb the ghost-gum.\n");
  this_player()->move_player("up the ghost gum#"+PATH+"tree1");
  return 1;
}
