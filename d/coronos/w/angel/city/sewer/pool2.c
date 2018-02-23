#include <mudlib.h>

#define GEM	"objects/components/gem"

#define PATH		"d/coronos/w/angel/city/sewer/"

inherit ROOM;

void reset(status arg) {
  if(random(3)) {
    if(!present("gem")) {
      move_object(clone_object(GEM), this_object());
    }
  }

  if(arg) return;
  set_short("a sewer");
  set_long(
"You're in a dark room of stagnant water and heavy methane in the air.\n");
  set_weather(0, 1, 0);
  set_exits(({
	PATH+"sewer28", "out",
  }));
}
