#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    reset_doors(0);
    ::reset(arg);


	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "A small abandoned building stands to the north, its windows boarded \n"+
	  "over. Skydda Street leads to the east, the road seemingly dark \n"+
	  "and dreary. To the northwest D'Tagma Way leads further into \n"+
	  "Ille Coronos.");
	set_day_desc(
	  " A tall oil lamp stands unlit at this time.\n");
	set_night_desc(
	  " The oil lamp illuminates the intersection.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "Stones laid side by side in careful fashion, worn a great deal \n"+
	    "over time, forms D'Tagma Way of Ille Coronos.\n",
	    "bush#bushes",
	    "Small leafy plants that have grown to about two feet in height \n"+
	    "and form a line along the side of the road.\n",
	    "grass",
	    "Pushing its way up through the stones the blades seemingly \n"+
	    "reach for the sky.\n",
	    "building",
	    "It seems to have been abandoned and left for years.\n",
	  }));
	set_day_items(({
	    "lamp#light#oil lamp post#lamp",
	    "The oil lamp stands about seven feet tall and the wick is \n"+
	    "encased by glass and steel, unlit for now.\n",
	  }));  
	set_night_items(({
	    "lamp#light#oil lamp post#lamp",
	    "The oil lamp stands about seven feet tall and the wick is \n"+
	    "lit, illuminating the street below. It has been encased by \n"+
	    "glass and steel, protecting the flame from wind and rain.\n",
	  }));
	set_smell(
	  "A salty smell on the air brushes your nose from the southeast\n");
	set_listen(
	  "Boots upon stone, voices, and other bustling sounds fill the air \n"+
    "about you in this busy section of the city of Ille Coronos.\n");
	set_weather(2, 4, 0);
	set_exits(({
	    "/d/coronos/w/darkness/mainst5","northwest",
	    "/d/coronos/w/alena/ille/sk_1","east",
	    "/d/coronos/w/alena/ille/c_6","southeast",
	  }));
    }
