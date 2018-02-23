#include <mudlib.h>
#include "paths.h"


inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("a trail");
  set_long(
"A simple trail meanders its way across the soft grasses\n"+
"and large acres of farming land. In the distance you spy.\n"+
"a large forest.\n");
  
  set_items(({
	"trail", "It doesn't appear well used.\n",

"grass#grasses", 
"They look quite green. The irrigation system in these parts \n"+
"must be very good. Perhaps dwarves built it?",

"farming land#land",
"The farming land looks sparsely populated",
  }));



  set_weather(1, 1, 0);
  
}
