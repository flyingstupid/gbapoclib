#include <mudlib.h>
#define PATH		"d/coronos/w/angel/city/docks/"
#define MONST		"d/coronos/w/angel/city/monst/"

inherit ROOM;

void reset(status arg) {
  int i;
  object obj;

  if(!query_day() && !present("rat")) {
    for(i=0; i<random(5); i++) {
      obj = clone_object(MONST+"rat");
      move_object(obj, this_object());
    }
  }
  else {
    if(!present("galaon")) {
      obj = clone_object(MONST+"merchant");
      move_object(obj, this_object());
    }
  }

  if(query_day())
    set_listen(
	"All you can hear is the bustle of people bustling about\n"+
	"the lane, loading wagons and their warehouses.\n");
  else
    set_listen(
	"The lane is unusually peaceful tonight...\n");

  if(arg) return;

  set_short("the Ille Coronos docks");

  set_day_desc(
"Large warehouses stand on each side of the lane that backs  \n"+
"onto the docks in the city of Ille Coronos. The street is   \n"+
"very clean, even though there is a bustle of people hurrying\n"+
"here and there.\n");

  set_night_desc(
"The large warehouses look strangely dark and ominous in the \n"+
"light of the moon. It is unusually quiet compared to what   \n"+
"you are used to seeing. The only sound you can hear is the  \n"+
"waves crashing agaist the beach.\n");

  set_items(({
	"people",
	"Some are merchants, some are peasants hoping to \n"+
	"get a job from loading cargo",
	"lane",
	"It looks dark and spooky",
	"dock#docks",
	"The merchant ships dock to the east",
  }));

  set_night_items(({
	"warehouse#warehouses",
	"They look dark and ominous",
  }));


  set_day_items(({
	"warehouse#warehouses",
	"They are open and being loaded with merchandise",
  }));

  set_weather(1, 3, 0);
  set_exits(({
	PATH+"dock6", "southwest",
  }));
}
	
