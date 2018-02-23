#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

set_short("A burial mound");
  set_long(
"\tA burial mound\n"+
"You stand on top of an ancient burial mound. It is obvious that the\n"+
"mound though impressive, was once much larger.  Several moss covered\n"+
"boulders are sitting in a circle.  You feel as if you are carrying\n"+
"a large weight. The gloom is absolutly impenetrable.\n");



set_weather(-1,1,1);
  set_exits(({

"d/coronos/w/mycroft/moor2.c","west",
"d/coronos/w/mycroft/mound1.c", "circle",
  }));
}
