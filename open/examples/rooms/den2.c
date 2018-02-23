#include <mudlib.h>
#define PATH "d/coronos/w/angel/city/gardens/"
#define MONST "d/coronos/w/angel/city/monst/"
inherit ROOM;
void reset(status arg) {
    object obj;
    if(!present("dingo")) {
	move_object(clone_object(MONST+"madingo"),this_object());
    }
    if(arg)return;
    set_weather(1,3,0);
    set_short("a dingo den");
    set_long(
      "Deep within the den it is very dark and cool. The ground \n"+
      "is softer here, due to the constant churning of the soil \n"+
      "to make for soft beds for the dingos that call this den \n"+
      "their home. The walls and roof are rounded, making this \n"+
      "back room feel small and inclosed.\n");
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
	PATH+"den1","out",
      }));
}

