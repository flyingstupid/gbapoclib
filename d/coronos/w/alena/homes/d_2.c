
#include <mudlib.h>


inherit ROOM;
void reset(status arg) {
    if(arg) return;

set_short("D'Vron Street");
    set_long(
" A small pathway leads to the north, upto a small home with a large \n"+
"oak tree in the front. The home seems to be very old, yet has been kept \n"+
"up and taken care of. D'Vron Street runs west and east from here.\n");

    set_items(({
	"road#path#dirt#street",
	"It is packed down from constant wear and proves to be seemingly dull",
"house#home#old house",
"Built with decaying wood the home stands two stories, which is very rare \n"+
"to find here in Ille Coronos. A huge oak tree hides most of the home.",
"oak tree#tree#oak",
"The tree grows very tall and its branches seem to protect the home by \n"+
"almost holding it within its branchlike arms.",
	"Looking alike they line the streets on either side of the street.",
	"pole#street lamp#lamp",
	"Hanging from a short chain it tosses and turns in the wind. Panes of glass \n"+
	"protect the candle within and darkened steel forms the housing.",

      }));

    set_weather(2,2,0);

    set_exits(({
"/d/coronos/w/alena/homes/d_1","west",
	"/d/coronos/w/alena/homes/d_3","east",
"/d/coronos/w/alena/homes/hom1/path","north",
      }));
}



