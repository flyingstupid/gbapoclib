#include "/players/relgar/mydefs.h"
inherit ROOM;

void reset(status arg) {
    if(arg) return;
    set_short("the Ille Coronos docks");
    set_long(
      "        You stand at one end of the docks of Ille Coronos. Most of\n\
the traffic on the docks passes through here and thus there is less\n\
clutter here to allow carts to get to the larger merchant ships.\n\
The clamour of the main section of docks is somewhat diminished\n\
and the rhythmic swell of the ocean is more evident.\n"
    );
    set_weather(1, 4, 6);
    set_smell("The briny smell of the ocean fills your nostrils.\n");
    set_listen("You hear the distant shouts of workers on the docks but the rythmic waves\n\of the ocean are prevalent and bring with them serenity.\n");
    set_exits(({
	STREETS+"dock2", "northeast",
      }));
}

