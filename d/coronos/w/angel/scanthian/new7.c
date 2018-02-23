#include <mudlib.h>
#include "paths.h"

inherit ROOM;

#define OX 3

object *oxes;

void reset(status arg) {
  int i;
  object ox;
  
  reset_doors(arg);
  load_door(({
	"file", PATH+"cabin1",
     "direction", "north door",
     "long", "A solid wooden door",
     "key id", "city key",
  }));

  if(!arg) {
    set_short("Cabin Yard");
    set_long(
"You are in the yard of a log cabin. From the amount of tools lying  \n"+
"around, you could say this is where the wood elves come do there    \n"+
"their work; such things as chopping wood, making furniture and other\n"+
"stuff. This bunch of elves are a lot stronger and a lot tougher than\n"+
"the other elves. They're not pushovers.\n");
    set_exits(({
	PATH+"new5", "south",
    }));
    set_items(({
       "tools",  "Small axes and hammers",
       "cabin",  "A small log cabin, feel free to go inside",
    }));
    set_weather(2,4,3);
  }
  if(!oxes) oxes = allocate(OX);
  for(i = 0; i < OX; i++) {
    if(!oxes[i]) {
       ox = clone_object(MONSTER);
       ox->set_name("ox");
       ox->set_short("an ox");
       ox->set_plural("oxen");
       ox->set_long(
          "A large elfin dog; a cooshee. The elves use these dogs, not\n"+
          "only as companions, but also as watch dogs. These dogs watch\n"+
          "over the wood items the elves will trade with the humans in "+
          "Tempus city.\n");
       ox->set_level(4);
       ox->set_ac(4);
       ox->set_wc(8);
       ox->set_race("ox");
       move_object(ox, this_object());
       oxes[i] = ox;
    }
  }
}
