#include <mudlib.h>
inherit ROOM;

void reset (status arg){
/*
    reset_doors(0);
*/
    ::reset(arg);

    if(!arg)
    {
/*
	load_door(({
	    "destination","/d/coronos/w/whoknows",
	    "direction",   "south door",
	    "closed",
	    "description",
	    "A heavy oak door on sturdy hinges.\n",
	  }));
*/

	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "Skydda Street bends both to the north and west at this elbow. A \n"+
	  "smithy's shop stands to the south. The dirt making the road is \n"+
	  "full of many different footprints.");
	set_day_desc(
	  " A tall oil lamp stands \n"+
	  "to the side of the road.\n");
	set_night_desc(
	  " The oil lamp stands \n"+
	  "dark and unlit.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "The road is made up of dirt and footprints. Skydda Street turns \n"+
	    "here and travels west and north.\n",
	    "footprints#prints#print",
	    "Those of men, women, and wagon wheels.\n",
	    "dirt",
	    "A grainy substance that makes up the road.\n",
	    "smithy#shop",
	    "A shop set up and run by a basic smithy.\n",
	  }));
	set_day_items(({
	    "lamp#light#oil lamp post#lamp",
	    "The oil lamp stands about seven feet tall and the wick isn't \n"+
	    "encased by glass and steel, unlit for now.\n",
	  }));  
	set_night_items(({
	    "lamp#light#oil lamp post#lamp",
	    "The oil lamp stands about seven feet tall and the wick is \n"+
	    "not lit, the glass having been broken around the wick.\n",
	  }));
	set_smell(
	  "Dampness and musty air covers all other smells.\n");
	set_listen(
	  "Due to the dirt road footsteps are muffled, making it much more \n"+
	  "quiet in the section of the commercial area.\n");
	set_weather(1, 4, 0);
	set_exits(({
	    "/d/coronos/w/alena/ille/sk_1","west",
	    "/d/coronos/w/alena/ille/sk_3","north",
	  }));
    }
}
