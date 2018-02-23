#include <mudlib.h>
inherit "inherit/room2";

reset (arg) {
    if (arg) return;
    set_weather(2,2,0);
    set_light(2);
    set_exits(({
	"room/city/square","square",
      }));
    set_smell("You smell the odor of old books and burning inscense.\n");
    set_listen("You can hear the chanting and praying of priests.\n");
} /* end of reset */

