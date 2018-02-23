#include <mudlib.h>

inherit ROOM;

void reset(status arg){

    if(arg)return;
    set_weather(1,3,0);
    set_short("a change in paths");
    set_long(
      "A building stands to the east, made of brick and stone. Two windows "+BS(n)+
      "face your way and are edged with shutters. The path is lined with "+BS(n)+
"grass on both sides. A tall oak tree stands to the north."+BS(n));

    set_items(({
	"grass",
	"Small blades grow together to form the lush grass that lines the "+BS(n)+
	"path on either side."+BS(n),
	"shutters#building#brick building#bricks#brick",
	"The building is made up of bricks and stone, lined with shutters."+BS(n)+
	"The building to the south looks inviting and you can hear laughter "+BS(n)+
	"from within."+BS(n),
	"path#dirt path",
	"It leads to the northwest and southwest, with grass lining both sides."+BS(n),
      }));

    set_exits(({
	"/d/ooc/w/alena/ooc5","northwest",
	"/d/ooc/w/alena/ooc6","southwest",
	"/d/ooc/w/alena/ooc1","east",
      }));
}
