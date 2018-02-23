/* High Clerists Tower - hall2.c
 * Angel October 1993
 */

#include <mudlib.h>
#define PATH "d/coronos/w/angel/city/temple"
inherit ROOM;


void reset(status arg) {
  load_door(({
    "file", "d/coronos/w/angel/city/temple/entrance",
    "long",
      "A large solid door",
     "direction", "north door",
	"open",
    "key id", "city key",
  }));
  reset_doors(arg);

  if(arg) return;

  set_short("the hallway within the high clerists tower");
  set_long (
     "The white marble floor is highly polished, reflecting your gaze    \n"+
     "as you look down onto it. The air within here is cool and crisp,   \n"+
     "exuding a feeling of peace and harmony. A few soft magical lights  \n"+
     "light the ways throughout the clerists tower. To the south an      \n"+
     "archway leads the way into the central chambers of the clerists tower.\n");

  set_items(({
     "floor#marble", "The floor is a highly polished marble",
     "reflection",    "It looks vaguely like you!",

     "light#lights#magical lights#magical light",
     "Soft magical lights line the way along the hallways",

     "arch#archway",
	"An ornate archway depicting scenes of heavenly beings.\n",
     "beings#heavenly beings",
	"They are the powerful winged servants of the All-God.\n",
  }));

  set_weather(2, 1, 0);

  set_exits(({
	"d/affils/rooms/all-god", "south",
	PATH+"/hall3", "east",
	PATH+"/hall1", "west",
  }));
}


     

void init() {
  ::init();
  add_action("check", "west");
  add_action("check", "east");
}

status check() {
  if((status)this_player()->id("PLAYER") &&
     (int)this_player()->query_age() < 300) {
    write("You shouldn't be going in there just yet.\n");
    say((string)this_player()->query_name()+" hesitates for a moment.\n");
    return 1;
  }
  return 0;
}
