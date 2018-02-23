#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

set_short("Mispec Moor");
  set_long(
"\tMispec Moor\n"+
"You stand a piece of firm ground in the middle of the bog.  Strange\n"+ 
"sounds occasionally echo through the mists and the smell of decay\n"+
"fills the air, to your west you see a burrow of some kind.  To your\n"+
"east is a large mound rising up out of the mire.\n");




set_weather(-2,1,1);
  set_exits(({
"d/coronos/w/mycroft/moor1.c","west",
"d/coronos/w/mycroft/moor3.c","east",
  }));
}
