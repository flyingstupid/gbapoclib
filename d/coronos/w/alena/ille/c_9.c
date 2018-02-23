#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;
  int i;

  if(!present("citizen")) {
    ob = clone_object("d/coronos/w/angel/city/monst/citizen");
    move_object(ob, this_object());
  }

    reset_doors(arg);
    ::reset(arg);


	set_short("the commercial sector of Ille Coronos");
	set_long(
	  "The northeast by northwest road of Eastern Commerce is paved in \n"+
	  "grey brick and lined in well cared for bushes which line both sides \n"+
	  "of the street. A seemingly empty building stands to the west and \n"+
	  "through the bushes you can see the docks of Ille Coronos.");
	set_day_desc(
	  " The \n"+
	  "lamp doesn't need to be lit right now and stands dark.\n");
	set_night_desc(
	  " The \n"+
	  "oil lamp shines brightly, illuminating the street.\n");
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
      "building",
      "The building looks empty.\n",
      "docks",
      "The docks are bustling with people.\n",
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
	    "/d/coronos/w/alena/ille/c_10","northeast",
	    "/d/coronos/w/alena/ille/c_8","southwest",
	  }));
    }
