#include <mudlib.h>
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
  object obj;

  if(!present("tree")) {
obj = clone_object("/obj/skills/tree");
    move_object(obj, this_object());
    obj -> grow();
  }

  if(arg) return;

  set_short("the city garden");
  set_long(
     "The path winds through the city gardens close to a large banksier. \n"+
     "This tall bush bears prickly red bottle-brush shaped blooms of great\n"+
     "beauty. "); 
  set_day_desc(
     "The sunlight beams down on you from on high, peeking through the \n"+
     "white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as dark sinister clouds pass by.\n");

  set_listen("The air is silent; the sound of peace.\n");
  set_smell("The air is full of the sweet honey smell of the banksier.\n");

  set_items(({
     "bottle-brush#bush#brush#bottle#banksier",
          "The big banksier bush bears simple flowers similar to bottle "+
          "brushes,\nthat taste similar to honey",
     "path#cobblestone path#cobblestones#cobblestone",
          "A well travelled cobblestone path",
     "tree#gum tree#ghost-gum#gum",
          "This tree's trunk is a light grey, almost white colour. Atop \n"+
          "the tree is some movement amid the leaves",
  }));
  set_day_items(({
     "sunlight#sun#light",
          "Do you want to go blind?",
     "cloud#clouds",
          "They are white and fluffy. One reminds you of an echidna",
  }));

  set_night_items(({
     "moon",
          "You can see the man in the moon. He \n"+
          "appears to be grinning an evil grin at you",
     "cloud#clouds",
          "They look dark and sinister...and very spooky",
  }));
  set_exits(({
	"d/coronos/w/angel/city/gardens/garden1", "north",
	"d/coronos/w/angel/city/gardens/garden7", "south",
	"d/coronos/w/angel/city/gardens/garden4", "east",
	"d/coronos/w/angel/city/gardens/garden2", "west",
  }));
  set_weather(1,4,0);
}

void init() {
  ::init();
  add_action("eat", "eat");
  add_action("eat", "taste");
}

status eat(string str) {
  string tmp1, tmp2;

  if(!str) {
    notify_fail("Taste what?\n");
    return 0;
  }
  if(!sscanf(str, "%sbanksier%s", tmp1, tmp2)) {
    notify_fail("Eat what? The banksier?\n");
    return 0;
  }
  if(this_player()->eat_food(1)) {
    tell_object(this_player(), "The banksier bush tastes like honey.\n");
    say(NAME+" tastes the banksier bush flowers.\n",this_player());
    return 1;
  }
  return 0;
}
