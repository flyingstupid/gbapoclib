#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
	"file", "d/coronos/w/darkness/arch1",
	"direction", "southwest gate",
	"unlocked",
	"long",
               "A grand set of double doors, almost as wide as they \n"+
               "are tall, and bound in steel and gold. Two great    \n"+
               "gargoyles stand over the tops of the gate watching  \n"+
               "your every move.\n",
    }));

  if(!present("apprentice")) {
    move_object(clone_object(MONST+"/apprentice"), this_object());
  }

  if(arg) return;
  set_short("the university of power");
  set_long(
	"The path to the university is a simple loose grey stone road \n"+
	"that winds to the north. To each side are simple trees that  \n"+
	"seem to be waiting for some event in order to bloom.\n");
  set_night_desc(
	"At the side of the road is a tall lamp stand, shedding light  \n"+
	"onto the path.\n");

  set_items(({
	"stones#grey stone#road",
	"The road's surface is made from a number of loose grey stones.\n",
	"tree#trees",
	"Ther are native gum trees, like the ones in the city gardens.\n",
  }));

  set_weather(1, 1, 0);
  set_exits(({
	PATH+"/path2", "northeast",
  }));
}
