#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    reset_doors(0);
    ::reset(arg);

    if(!arg)
    {
	load_door(({
  "destination", "/d/coronos/w/vorax/armour",
	    "direction",   "east door",
	    "closed",
	    "description",
	    "A heavy oak door on sturdy hinges.\n",
	  }));
	load_door(({
  "destination", "/d/coronos/w/vorax/weapons",
	    "direction","west door",
	    "closed",
	    "description",
	    "A heavy maple door with a carving of a sword on it.\n",
	  }));

	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "The road ends here, two shops on either side of the steet to \n"+
	  "the west and east. A tall oak tree stands to the northeast \n"+
	  "and its branches hang over the tall wooden fence blocking the \n"+
	  "passage to the north.");
	set_day_desc(
	  " An oil lamp stands to the side of the \n"+
	  "the road. A sign hangs from the wooden fence.\n");
	set_night_desc(
	  " The oil lamp stands dark and \n"+
	  "unlit. A sign hangs from the wooden fence.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "The road is made up of dirt and footprints. Skydda Street deadends \n"+
	    "here with shops to the west and east.\n",
	    "footprints#prints#print",
	    "Those of men, women, and wagon wheels.\n",
	    "dirt",
	    "A grainy substance that makes up the road.\n",
	    "shops#shop",
	    "Shops that have been set up to better Ille Coronos.\n",
	    "oak#tall oak#oak tree",
	    "Its thick trunk leads upto huge branches that hang over the \n"+
	    "tall wooden fence to the north.\n",
	    "fence#wooden fence",
	    "Made from planks the fence blocks the way to the north.\n",
	  }));
	set_sign_message(
	  "<----- Weaponsmith  \n"+
	  " Armourer -----> \n");
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
	    "/d/coronos/w/alena/ille/sk_2","south",
	  }));
    }
}
