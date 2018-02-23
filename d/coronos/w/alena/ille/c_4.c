#include <mudlib.h>
inherit ROOM;

void reset (status arg){
reset_doors(arg);
	load_door(({
            "destination", "d/coronos/w/silvara/papershop",
	    "direction",   "west door",
	    "description",
	    "A heavy oak door on sturdy hinges.\n",
	  }));

if(arg) return;
	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "The street known as Western Commerce carries travelers northeast and \n"+
	  "southwesterly over well worn grey stones. Small bushes line the edges \n"+
	  "of the road while grass tries to grow up through the small cracks. \n"+
	  "Gshone Street branches off to the east while a sturdy oak door \n"+
	  "stands just off the road to the north.");
	set_day_desc(
	  " The lamp is unlit and \n"+
	  "stands at the side of the street.\n");
	set_night_desc(
	  " The oil lamp is lit and its \n"+
	  "glow illuminates Western Commerce.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "Stones laid side by side in careful fashion, worn a great deal \n"+
	    "over time, forms Western Commerce of Ille Coronos.\n",
	    "bush#bushes",
	    "Small leafy plants that have grown to about two feet in height \n"+
	    "and form a line along the side of the road.\n",
	    "grass",
	    "Pushing its way up through the stones the blades seemingly \n"+
	    "reach for the sky.\n",
      "cracks",
      "These cracks in the stone are allowing grass to seep through.\n",
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
	    "/d/coronos/w/alena/ille/c_3","northeast",
	    "/d/coronos/w/darkness/mainst5","southwest",
	    "/d/coronos/w/alena/ille/g_1","east",
	  }));
    }
