/* ILLE CORONOS - GATE 1 (north gate) */

#include <mudlib.h>

#define PATH    "d/coronos/w/angel/city/streets/"
#define MONST   "d/coronos/w/angel/city/monst/"

inherit ROOM;

void reset(status arg) {
  int i;


  if(!present("guard")) {
    for(i=0; i<4; i++) {
      move_object(clone_object(MONST+"guard1"),this_object());
    }
  }

  load_door(({
   "file",	PATH+"nroad1",
   "direction", "north gate",
   "key id", 	"city key",
   "long",
      "A huge set of large iron gates, standing about 30 feet tall.\n",
  }));

  if(arg) return;
  set_short("the North Gate of Ille Coronos");

  set_long(
	"\tNorth Gate.\n"+
	"Main street comes to an end here in the north part of Ille Coronos.\n"+
	"A fine road of large slate stones, carved with careful hands leads \n"+
	"away to the south. The North Gate is the main defense against      \n"+	"possible attacks from the northern realms and the Drow. To the     \n"+
	"south are the city gardens, and beyond it, the inner wall.         \n");

  set_night_desc(
     "Tall bronzed torch stands shed light here beside the grand gates.\n");


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

	"inner wall#wall#city wall",
        "The inner wall of the city that keep intruders out",
	"garden#gardens",
	"The gardens of Ille Coronos were designed by Aurora Shadowborne,\n"+
	"a member of The Circle. Her hands governed the beautification   \n"+
	"of the city with the aid of Princess Tilshannar.\n",
  }));

  set_weather(1,1,0);

  set_exits(({
	PATH+"main1", "south",
	PATH+"wall5",  "west",
	PATH+"wall6",  "east",
  }));

}
