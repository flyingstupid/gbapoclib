/* High Clerists Tower - sanctum3.c
 * Angel October 1993
 */

#include <mudlib.h>
#define PATH	"d/coronos/w/angel/city/temple/"
#define MONST	"d/coronos/w/angel/city/monst/"
inherit ROOM;

void reset(status arg) {
  int i;

  if(!present("cleric")) {
    for(i=0; i<3; i++) {
      move_object(clone_object(MONST+"cleric"), this_object());
     }
  }

  if(arg) return;

  set_short("a small quiet sanctum");
  set_long(
     "This is a small room, quiet and peaceful; a place where worshipers \n"+
     "meet to discuss holy things, and matters of the church. The white  \n"+
     "marble floor is higly polished, and in its centre is a fine woven  \n"+
     "rug of plush blue and silver wools. The air here is cool and crisp,\n"+
     "lit by a small glowing orb in the corner on a small pedestal. \n");

  set_items(({
     "floor#marble#reflection",
          "You can see yourself in the reflection in the higly polished "+
          "marble floor",

     "light#lights#magical lights#magical light#globe of light#globe",
          "A small orb of light atop a silver stand sits in the corner",

     "woolen rug#woven rug#rug",
          "A fine blue and silver rug sits in the middle of the floor",

     "pedestal#small pedestal",
          "A silver pedestal which supports a small globe of light",
     
  }));

  set_weather(2, 1, 0);

  set_exits(({
	PATH+"hall3", "west",
  }));
}     
