#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("the commercial sector of Ille Coronos");
    set_long(
      "The grey stones that pave D'Tagma Way to the west give way to a \n"+
      "dirt road running to the east, into a dark and secluded section \n"+
      "of Ille Coronos. The many numbers of footprints laying in the dirt \n"+
      "tend to prove this road is well traveled.");
    set_day_desc(
      " A tall lamp stands \n"+
      "to one side.\n");
    set_night_desc(
      " A tall lamp stands \n"+
      "to one side, remaining dark.\n");
    set_items(({
	"road#street#walkway#walk",
	"Many footprints lay in the dirt. Skydda Street runs west and east.\n",
	"footprint#footprints#prints",
	"Boots from all various sides have made the many prints.\n",
	"dirt",
	"A grainy substance that makes up the road.\n",
      }));
    set_day_items(({
	"lamp#light#oil lamp post#lamp",
	"The oil lamp stands about seven feet tall and the wick is \n"+
	"encased by glass and steel, unlit for now.\n",
      }));  
    set_night_items(({
	"lamp#light#oil lamp post#lamp",
	"The oil lamp stands about seven feet tall and the wick isn't \n"+
	"lit, the glass surrounding the wick having been broken.\n",
      }));
    set_smell(
      "Smell of decaying garbage strikes your nose.\n");
    set_listen(
      "The clanging of metal on metal can be heard from the east.\n");
    set_weather(1,4,0);
    set_exits(({
	"/d/coronos/w/alena/ille/c_5","west",
	"/d/coronos/w/alena/ille/sk_2","east",
      }));
}
