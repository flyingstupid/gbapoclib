#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    reset_doors(0);
    ::reset(arg);

    if(!arg)
    {
	load_door(({
            "destination", "d/coronos/w/silvara/glassshop",
	    "direction",   "oak door",
	    "closed",
	    "description",
	    "A heavy oak door on sturdy hinges.\n",
	  }));

	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "Traveling along Gshone Street the paving of grey stones seems \n"+
	  "to appear worse as it continues to the west. Some stones seem to \n"+
	  "be missing, along with many chips out of the ones that lay upon the \n"+
	  "road. Grass pokes its blades up through the spaces.");
	set_day_desc(
	  " The lamp is unlit and \n"+
	  "stands at the side of the street.\n");
	set_night_desc(
	  " The oil lamp \n"+
	  "is lit and its glow illuminates Gshone Street.\n");
	set_items(({
	    "road#stone#stones#walk#walkway#street",
	    "Grey stones pave the road, consisting of many holes and chips \n"+
	    "obtained over the many years of use.\n",
	    "grass",
	    "Pushing its way up through the stones the blades seemingly \n"+
	    "reach for the sky.\n",
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
	  "about you in thie busy section of the city of Ille Coronos.\n");
	set_sign_message(
	  " =+= Glassblower =+= \n");
	set_weather(2, 4, 0);
	set_exits(({
	    "/d/coronos/w/alena/ille/g_1","west",
	    "/d/coronos/w/alena/ille/g_3","east",
	  }));
    }
}
