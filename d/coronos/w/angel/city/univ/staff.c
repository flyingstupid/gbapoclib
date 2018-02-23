#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {
  int i;

  if(!present("apprentice")) {
    for(i=0; i<6; i++) {
      move_object(clone_object(MONST+"/appr1"), this_object());
    }
  }

  if(arg) return;

  set_short("the University of Power");
  set_long(
"Several wooden bunks stand here in the servants quarters of the university. \n"+
"Beside them are large chests where they store their personal effects. The   \n"+
"whole room looks clean and tidy and well kept.\n");

  set_weather(2, 1, 0);

  set_items(({
"bunks", "There are eight bunks in this room, all of strong design",
    	"chest", "Each chest bears the name of its owner",
  }));

  set_listen("You can hear someone snoring from one of the bunks.\n");
  set_smell("You can smell stew from the kitchen nearby.\n");

  set_exits(({
	PATH+"/kitchen", "east",
  }));
}


