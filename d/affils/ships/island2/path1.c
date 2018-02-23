#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  object ob;

  if(!present("bear")) {
    ob = clone_object(PATH+"bear");
    move_object(ob, this_object());
  }

  if(arg) return;

  set_short("a simple path");
  set_long(
"A simple well trodden trail winds its way through the tall grasses\n"+
"toward a grove of trees.\n");


  set_items(({
"trail", "The trail appears used recently, but also has some large\n"+
"animal tracks",
"grass#grasses", "The grasses in this field are nearly a metre tall",
"grove#trees", "The grove of trees looks very peaceful",
}));


  set_exits(({
	PATH+"cliff4", "north",
	PATH+"path2",  "south",
  }));
  
  set_climb(10);
  set_fall_dam(10);

  set_listen(
"The sounds of waves crashing against the rocks echoes up the cliffs and\n"+
"through the little field");

  set_search_array(({
"trail#grass#grasses",
"You notice some bear tracks on the trail. They lead south\n",
  }));

  set_weather(1, 1, 6);
}


