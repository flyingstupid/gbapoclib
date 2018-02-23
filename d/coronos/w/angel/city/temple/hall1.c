/* High Clerists Tower - hall1.c
 * Angel October 1993
 */

#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/temple/"

inherit ROOM;
void reset(status arg) {
  if(arg) return;

  set_short("the hallway within the high clerists tower");
  set_long(
     "The white marble floor is highly polished, reflecting your gaze  \n"+
     "as you look down onto it. The air within here is cool and crisp, \n"+
     "exuding a feeling of peace and harmony. A few soft magical lights\n"+
     "light the ways throughout the clerists tower.\n");

  set_items(({
     "floor#marble#reflection",
          "You can see yourself in the reflection in the higly polished "+
          "marble floor",

     "light#lights#magical lights#magical light",
          "The soft magical lights line the hallways"
  }));

  set_weather(2, 1, 0);

  set_exits(({
	PATH+"sanctum1", "north",
	PATH+"hall2", "east",
	PATH+"sanctum2", "west",
  }));
}


     
