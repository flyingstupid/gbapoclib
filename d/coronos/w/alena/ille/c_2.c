#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    reset_doors(arg);
    load_door(({
	"destination","d/coronos/w/silvara/bakery",
	"direction",   "west door",
	"closed",
	"description",
	"A simple oak door on somewhat rusty hinges.\n",
      }));
    if (arg) return;
    set_short("the commercial sector of Ille Coronos");
    set_long(
      "The street of Western Commerce, paved with stones that have been worn \n"+
      "down due to frequent travelers, runs to the northeast as well as to \n"+
      "the southwest. The narrow road is lined by bushes and only very few \n"+
      "blades of grass have been able to make their way up and through the \n"+
      "stones, as if reaching for the sky.");
    set_day_desc(
      " The lamp is unlit at this time and \n"+
      "stands at the side of the street.\n");
    set_night_desc(
      " The oil lamp has been lit and its \n"+
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
      "to float in from the east.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in this busy section of the city of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/alena/ille/c_1","northeast",
	"/d/coronos/w/alena/ille/c_3","southwest",
      }));
}
