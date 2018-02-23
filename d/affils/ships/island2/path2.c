#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("a simple path");
  set_long(
"A path winds north towards a cliff face, high above the beach. The \n"+
"south trail passes through long grasses toward a grove of trees.\n");


  set_items(({
"cliff#cliff face", "The cliff is north",
"trail", "The trail appears used recently, but also has some large\n"+
"animal tracks",
"grass#grasses", "The grasses in this field are nearly a metre tall",
"grove#trees", "The grove of trees looks very peaceful",
}));


  set_exits(({
	PATH+"path1", "north",
	"d/affils/rooms/werebear", "south",
  }));
  

  set_listen("There are birds chirping in the trees\n");

  set_search_array(({
"trail#grass#grasses",
"You notice some bear tracks on the trail. They lead south\n",
  }));

  set_weather(1, 1, 6);
}


