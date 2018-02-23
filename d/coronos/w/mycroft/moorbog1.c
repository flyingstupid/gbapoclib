#include <mudlib.h>
inherit ROOM;


void reset(status arg) {
  if (arg) return;
set_short("A patch of quicksand!");
set_long("While carefully threading your way from one patch of\n"+
"semi-solid ground to another, you slip and fall into QUICKSAND!\n"+
"You must escape quickly or drown!\n"+
"\n");
set_weather(1,1,-1);
set_exits (({"d/coronos/w/mycroft/moor1.c","north",
"d/coronos/w/mycroft/moundx.c","down",}));
}
