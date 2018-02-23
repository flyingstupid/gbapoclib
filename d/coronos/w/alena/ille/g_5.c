#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("the commercial sector of Ille Coronos");
    set_long(
      "Paved with smooth grey stones, Gshone Street stretches from west \n"+
      "to east and is lined on either side by bushes that have been well \n"+
      "cared for. A major intersection lies to the east and the road \n"+
      "travels to the south just west of here.");
    set_day_desc(
      " A tall lamp stands unlit.\n");
    set_night_desc(
      " The oil lamp is lit \n"+
      "and the small flame illuminates the street.\n");
    set_items(({
	"road#stone#stones#walk#walkway#street",
	"Grey stones line the road. Gshone flows from west to east.\n",
	"grass",
	"Pushing its way up through the stones the blades seemingly \n"+
	"reach for the sky.\n",
	"bush#bushes#line of bushes",
	"Standing about two to three feet high they form a wall to the \n"+
	"north and south.\n",
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
	"/d/coronos/w/alena/ille/g_4","west",
	"/d/coronos/w/alena/ille/c_12","east",
      }));
}
