#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    reset_doors(0);
    ::reset(arg);

    if(!arg)
    {
	load_door(({
	    "destination", "d/coronos/w/vorax/cloth",
	    "direction",   "west door",
	    "closed",
	    "description",
	    "A simple oak door on somewhat rusty hinges.\n",
	  }));

	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "Many sounds of the sea to the east mix with the salty smell upon \n"+
	  "the air. Eastern Commerce meets up with PyRosh Avenue northeast \n"+
	  "from here and travels back to the southwest. Along the eastern \n"+
	  "boarder of the road bushes grow thick and hearty.");
	set_day_desc(
	  " The lamp is \n"+
	  "unlit and stands dark at the side of the road.\n");
	set_night_desc(
	  " The oil lamp has \n"+
	  "been lit and illuminates Eastern Commerce and the doorstep of \n"+
	  "the shop to the west.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "Stones laid side by side in careful fashion, worn a great deal \n"+
	    "over time, form Eastern Commerce of Ille Coronos.\n",
	    "bush#bushes",
	    "Small leafy plants that have grown to about two feet in height \n"+
	    "and form a line along the side of the road.\n",
	    "grass",
	    "Pushing its way up through the stones the blades seemingly \n"+
	    "reach for the sky.\n",
      "sea",
      "The sea is very rough.\n",
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
	  "Salty air floats in from the southeast, stinging your nose.\n");
	set_listen(
	  "Boots upon stone, voices, and other bustling sounds fill the air \n"+
    "about you in this busy section of the city of Ille Coronos.\n");
	set_weather(2, 4, 0);
	set_exits(({
	    "/d/coronos/w/alena/ille/c_11","northeast",
	    "/d/coronos/w/alena/ille/c_9","southwest",
	  }));
    }
}
