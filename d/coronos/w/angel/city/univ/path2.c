#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/univ"
inherit ROOM;

void reset(status arg) {

  reset_doors(arg);

  load_door(({
	"file", PATH+"/foyer",
	"direction", "east door",
	"unlocked",
	"long",
	"A grand set of double doors, bound in iron and gold, and bearing \n"+
	"several circles of stained glass windows. Each is a different    \n"+
	"colour; white, grey and black to represent the Three Robes .\n",
  }));

  if(arg) return;
  set_short("the university of power");
  set_long(
	"The university stands in all it's magesty to the north, while\n"+
	"the city of Ille Coronos and it's commercial district is to \n"+
	"the south.\n");

  set_night_desc(
	"At the side of the road is a tall lamp stand, shedding light  \n"+
	"onto the path.\n");

  set_items(({
	"stones#grey stone#road",
	"The road's surface is made from a number of loose grey stones.\n",
	"tree#trees",
	"Ther are native gum trees, like the ones in the city gardens.\n",
  }));

  set_weather(2, 1, 0);
  set_exits(({
	PATH+"/path1", "southwest",
  }));
}
