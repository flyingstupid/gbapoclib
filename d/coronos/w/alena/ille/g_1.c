#include <mudlib.h>
inherit ROOM;

void reset (status arg){
::reset(arg);

    if(!arg)
    {
    set_short("the commercial sector of Ille Coronos");
    set_long(
      "The street here still is paved with grey stone but they consist of \n"+
      "more cracks and occasionally stones are missing. The maintenance of \n"+
      "Gshone Street seems to be much less of a priority then that of \n"+
      "Western Commerce just to the west. Tall grass pokes up through \n"+
	"the bare patches in the road.\n");
    set_day_desc(
      " The lamp post is unlit and \n"+
      "stands at the side of the road.\n");
    set_night_desc(
      " The oil lamp is lit and lights \n"+
      "up Gshone Street.\n");
    set_items(({
	"road#stone#stones#walk#walkway#street",
	"The grey stones are placed in every which way, providing for gaps \n"+
	"in which grass has decided to grow, forming Gshone Street.\n",
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
      "You smell only a very light salty scent on the air to the southeast.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in thie busy section of the city of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/alena/ille/c_4","west",
	"/d/coronos/w/alena/ille/g_2","east",
      }));
}
}
