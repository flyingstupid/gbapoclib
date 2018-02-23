#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("the commercial sector of Ille Coronos");
    set_long(
      "Grey stone paves the street, worn smooth by countless boots and \n"+
      "other means of transportation. PyRosh Avenue runs to the northwest \n"+
      "and southeast, forming the eastern side of the commercial section of \n"+
      "Ille Coronos. Gshone Street leads to the west and small bushes line \n"+
      "the edges of the road.");
    set_day_desc(
      " The lamp remains unlit at this time.\n");
    set_night_desc(
      " The oil lamp is lit and lights \n"+
      "up PyRosh Avenue.\n");
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
      "The scent of what seems to be freshly baked bread seems to \n"+
      "be carried upon the air from the northwest.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in this busy section of the city of Ille Coronos.\n");
    set_sign_message(
      "Northwest and Southeast: PyRosh Avenue \n"+
      "West: Gshone Street \n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/alena/ille/c_13","northwest",
	"/d/coronos/w/alena/ille/g_5","west",
	"/d/coronos/w/alena/ille/c_11","southeast",
      }));
}
