#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  int i;
  object ob;

  if(!present("mouse")) {
    for(i=0; i<5; i++) {
      ob = clone_object(PATH+"mouse");
      move_object(ob, this_object());
    }
  }

  if(arg) return;

  set_short("the cliffs of I'tool'Zar Isle");
  set_long(
"From atop the cliffs of I'tool'Zar you can see the whole sea before you.\n"+
"The grass here is soft under your boots, and the air crisp and clean.\n");


  set_items(({
"cliff",
	"The cliff is very steep, but you may be able to climb down it.\n",
 "sea#seas",
	"The water looks good enough to go for a swim.\n",
}));


  set_exits(({
	PATH+"cliff3", "down",
	PATH+"path1", "south",
  }));
  
  set_climb(10);
  set_fall_dam(10);

  set_listen(
"You can hear the waves rolling up on the beach, and the squawk of gulls.\n");

  set_weather(1, 1, 6);
}


