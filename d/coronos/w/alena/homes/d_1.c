
#include <mudlib.h>


inherit ROOM;
void reset(status arg) {
    if(arg) return;

    set_short("the west end of D'Vron Street");
    set_long(
      " The road is less then fine brick that layers many other roads through \n"+
      "the town, rather it consists of hardened dirt by many sets of boots \n"+
      "and wagons which cross it. Homes line the streets and lamps hang from \n"+
      "poles standing tall beside the street edge. D'Vron Street runs west \n"+
      "and east from here.\n");

    set_items(({
	"road#path#dirt#street",
	"It is packed down from constant wear and proves to be seemingly dull",
	"homes#houses#house",
	"Looking alike they line the streets on either side of the street.",
	"pole#street lamp#lamp",
	"Hanging from a short chain it tosses and turns in the wind. Panes of glass \n"+
	"protect the candle within and darkened steel forms the housing.",

      }));

    set_weather(2,2,0);

    set_exits(({
	"/d/coronos/w/vorax/res5","west",
	"/d/coronos/w/alena/homes/d_2","east",
      }));
}



