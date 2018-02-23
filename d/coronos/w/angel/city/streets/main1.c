/* ILLE CORONOS   */

#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/streets/"
#define MONST 	"d/coronos/w/angel/city/monst/"

inherit ROOM;

void reset(status arg) {
  if(arg) return;
  set_short("the Main Street of Ille Coronos");

  set_long(
	"\tMain Street.\n"+
	"The grand North Gates stand tall against the might of the outside  \n"+
	"wall. Main street runs north and south through the middle of Ille  \n"+
	"Coronos; a fine road of gigantic grey stone slabs, carved by the   \n"+
	"careful hands of dwarvish stonemasons. To the far south a garden   \n"+
	"blooms behind the inner wall.\n");

  set_night_desc(
     "Tall bronzed torch stands shed light here beside the road side gates.\n");


  set_night_items(({
     "torch#stands#torch stands",
     "Flaming torches shed light into the square",
     "flame#fire#flames",  "It looks like the torch is on fire"
  }));


  set_items(({
	"road#stones#slate stones",
	"A road of large grey stones. It would have taken a whole army\n"+
	"of stone masons to lift this slab into place. It is rumoured \n"+
	"that dwarves were the architects of this road.\n",

	"wall#city wall",
        "The north wall of the city that keep intruders out",

	"inner wall",
	"The inner wall of the city, used primarily for defense in the "+
	"case of war.\n",
  }));

  set_weather(1,1,0);

  set_exits(({
	PATH+"gate1", "north",
	PATH+"main2", "south",
  }));

}
