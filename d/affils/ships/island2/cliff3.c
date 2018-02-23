#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the cliffs of I'tool'Zar Isle");
  set_long(
"The cliffs are steep. One fall and you could plummet to your death \n"+
"toward the rocks far below on the beach.\n");


  set_items(({
"cliff",
	"The cliff is very steep, but you may be able to climb it.\n",
 "sea#seas",
	"The water looks good enough to go for a swim.\n"+
	"If you had swimming skills perhaps you could jump in",
  }));


  set_exits(({
	PATH+"cliff2", "down",
	PATH+"cliff4", "up",
  }));
  
  set_climb(10);
  set_fall_dam(10);

  set_listen(
"You can hear the waves rolling up on the beach, and the squawk of gulls.\n");

  set_weather(1, 1, 6);
}


