#include <mudlib.h>
inherit SHIPS;

void reset(status arg) {
  if(!present("rachel")) {
    move_object(clone_object("d/coronos/w/angel/city/monst/rachel"),this_object());
  }

  ::reset(arg);
  if(arg) return;
  set_captain("Rachel");
  set_ship_name("tamiel");
  set_ship_speed(4);
  set_short("the Tamiel");
  set_long("The Tamiel is a skiff, a magical craft that hovers over the \n"+
	   "land and the water.\n");
  set_weather(2, 0, 0);
  set_ports(({ "minos", "ille coronos", }));

  set_exits(({
    "d/minos/w/sarak/minos/rooms/island/start", "gang plank",
  }));

}
