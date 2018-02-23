#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    ::reset(arg);

    if(!arg)
    {

	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "PyRosh Avenue travels the northwest, leading to the junction of \n"+
	  "Western Commerce. A bakery sits just off the road to the west \n"+
	  "and an open window allows for wonderful scents. An intersection \n"+
	  "lies just to the southeast. The stones paving the avenue are grey \n"+
	  "in color and show signs of wear.");
	set_day_desc(
	  " The lamp is unlit at this time and \n"+
	  "stands at the side of the street.\n");
	set_night_desc(
	  " The oil lamp has been lit and its \n"+
	  "glow illuminates PyRosh Avenue.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "Stones laid side by side in careful fashion, worn a great deal \n"+
	    "over time, forms PyRosh Avenue of Ille Coronos.\n",
	    "bush#bushes",
	    "Small leafy plants that have grown to about two feet in height \n"+
	    "and form a line along the side of the road.\n",
	    "grass",
	    "Pushing its way up through the stones the blades seemingly \n"+
	    "reach for the sky.\n",
      "bakery",
      "Great smells come from this bakery.\n",
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
	  "The smell of freshly baked goods is very strong here, seeming \n"+
	  "to float in from the west.\n");
	set_listen(
	  "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in this busy section of the city of Ille Coronos.\n");
	set_weather(2, 4, 0);
	set_exits(({
	    "/d/coronos/w/alena/ille/c_1","northwest",
	    "/d/coronos/w/alena/ille/c_12","southeast",
	  }));
    }
}
