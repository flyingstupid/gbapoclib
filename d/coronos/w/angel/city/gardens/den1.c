#include <mudlib.h>
#define PATH "d/coronos/w/angel/city/gardens/"
#define MONST "d/coronos/w/angel/city/monst/"
inherit ROOM;
void reset(status arg) {
    object obj;
    int i;
    if(!present("pup")) {
	for(i=0; i<2; i++) {
	    move_object(clone_object(MONST+"dingopup"),this_object());
	}
    }
    if(arg)return;
    set_weather(1,3,0);
    set_short("a dingo den");
    set_long(
      "Here just inside the den the roof is low, causing most to \n"+
      "stay low to the ground. The ground is made up of loose soil \n"+
      "and full of many dingo prints. The walls are formed in crude \n"+
      "rounded supports, and looks as if they have been formed due \n"+
      "to vigerous digging.\n");
    set_smell("The strong scent of dingo droppings override "+
      "everything else.\n");
    set_listen("An occasional yip reminds you of just how "+
      "close you are to the dingos.\n");
    set_items(({
	"roof#walls#soil#ground",
	"Made up of packed sandy soil due to frequent use",  
	"prints#footprints#dingo prints",
	"Little paw prints, but also larger prints of a larger \n"+
	"dingo. Could it be the mother of the pups?",  
      }));
    set_exits(({
	PATH+"garden12","out",
	PATH+"den2","in",
      }));
}

