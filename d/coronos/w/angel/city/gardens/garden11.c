#include <mudlib.h>
#define PATH "d/coronos/w/angel/city/gardens/"
#define MONST "d/coronos/w/angel/city/monst/"
inherit ROOM;

void reset(status arg) {
    reset_doors(0);
    load_door(({
	"destination", "d/coronos/w/alena/ille/mnstG",
	"direction",       "south gate",
	"closed",
	"description",
	"The gate is a beautifully crafted wrought iron gate.\n",
      }));

    if(arg)return;
    set_weather(1,3,0);
    set_short("the city garden");
    set_long(
      "The ground here seems to be more dirt then grass, and the \n"+
      "trees have become very sparse. The ground becomes less arid \n"+
      "to the north and south, but remains the same to the west \n"+
      "and east. A gate stands to the south.\n");
    set_exits(({
	PATH+"garden7","north",
	PATH+"garden10","west",
	PATH+"garden12","east",
      }));
}
