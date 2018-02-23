#define PATH	"/d/affils/ships/island"

#include <mudlib.h>

inherit ROOM;

void reset(status arg) {
  if(arg) return;
  set_short("the jetty");
  set_long(
     "You stand on a long jetty which extends out toward the great green \n"+
     "Sea of Jade. Many ropes of all sizes sit coiled here for when ships\n"+
     "from Tempus city set anchor.\n");

  set_items(({
     "jetty", "It looks quite strong and stirdy",
     "sea#green sea",
          "The waves of the sea wash up against the beach to the south",
     "beach",
          "A fine yellow sandy beach which extends up and down the coast",
     "coast",
          "The coast of Skol island",
     "rope#ropes",
          "Many coils of rope assist in tying ships to the jetty",
  }));

  set_extra_objects(({ "rope", "objects/rope", }));
  set_weather(1, 4, 6);
  set_exits(({
	PATH+"/beach1", "south",
  }));
}
