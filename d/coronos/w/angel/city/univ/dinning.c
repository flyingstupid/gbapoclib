#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {
  int i;
  reset_doors(arg);
  if(!present("apprentice")) {
    for(i=0; i<3; i++) {
      move_object(clone_object(MONST+"/apprentice"), this_object());
    }
  }

  if(!present("mouse")) {
    move_object(clone_object(MONST+"/mouse"), this_object());
  }



  if(arg) return;

  set_short("the University of Power");
  set_long(
"The dinning hall of the university is not only a place to eat, but also \n"+
"forms the social centre of the grand halls. It is here that many dances \n"+
"debates and other such activities are held. The long benches stretch all\n"+
"the way to the south of the hall where the kitchen doors swing in the   \n"+
"breeze blowing from the east windows.\n");


  set_weather(2, 1, 0);

  set_items(({
	"window#windows",
	"The windows look out onto the wharfs and the sea to the east.\n",
	"sea", "You can see the waves crashing against the beach",
	"beach", "It looks very inviting",
	"waves", "The waves look a little high today",
	"benches#bench", 
"They all stand parallel to each other ready for the next meal.\n",
"door#doors", 
"They lead into the kitchen from which you can smell wonderful foods!",
  }));

  set_listen("All is relatively quite in the dinning hall.\n");
  set_smell("The delights of the kitchen invite you southward.\n");

  set_exits(({
	PATH+"/room1",   "north",
	PATH+"/kitchen", "south",
  }));
}


