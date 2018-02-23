#include <mudlib.h>
#define PATH		"d/coronos/w/angel/city/docks/"
#define MONST		"d/coronos/w/angel/city/monst/"

inherit ROOM;

object ob, obj;
void reset(status arg) {
  int i;

  if(!ob) {
    ob = clone_object("d/coronos/w/angel/city/monst/karak");
    move_object(ob, this_object());
  }

  if(!query_day() && !present("rat")) {
    for(i=0; i<3; i++) {
      obj = clone_object(MONST+"rat");
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



  set_long(
"The lane to the docks winds east from here, shadowed in the \n"+
"looming ediface of the large wooden warehouses. The lane is \n");

  set_day_desc(
"bustling with many people, loading items ready for travel   \n"+
"on the high seas, and for sale here in Ille Coronos.\n");

  set_night_desc(
"Unusually quiet compared to what you are used to seeing. The\n"+
"only sound you can hear is the waves crashing agaist the beach.\n");

  set_items(({
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
	PATH+"dock7", "northeast",
	"d/coronos/w/chi/city/streets/dock3", "southeast", 
"/d/coronos/w/alena/ille/c_7","northwest",
  }));
}
	
void clean_up() { return; }
