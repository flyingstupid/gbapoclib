#include <mudlib.h>
#define PATH		"d/coronos/w/angel/city/sewer/"

inherit ROOM;

void reset(status arg) {
  object ob;
  if(!present("money")) {
    ob = clone_object(MONEY);
    ob -> set_money(1000);
    move_object(ob, this_object());
  }

  if(arg) return;
  set_short("a sewer");
  set_long(
"You're in a dark room of stagnant water and heavy methane in the air.\n");
  set_weather(0, 1, 0);
  set_exits(({
	PATH+"sewer7", "out",
  }));
}
