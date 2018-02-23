#include <mudlib.h>
inherit SHIPS;
void reset(status arg) {

  ::reset(arg);
  if(arg) return;
  set_captain("Araton");
  set_ship_name("sea turtle");
  set_ship_speed(3);
  set_short("the Sea Turtle");
  set_long(
	"While the Sea Turtle looks like a regular merchant sailing \n"+
	"vessel, the canons mounted on the sides would indicate that\n"+
	"she is also fit for battle. She has three masts, and her sails\n"+
	"are trim and in fine condition. \n");
  set_weather(2, 0, 0);
  set_ship_speed(3);
  set_ports(({
	"isle of sorcery", "ille coronos", "skol island",
  }));

  set_exits(({
	"d/coronos/w/angel/city/docks/dock1", "gang plank",
  }));
}
