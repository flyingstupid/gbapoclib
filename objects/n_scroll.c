#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
  if(arg) return;
  set_name("scroll");
  set_alias("newbie scroll");
  set_short("A yellowing scroll");
  set_long(
"It bears the symbol of the city of Ille Coronos.\n"+
	"It looks very important. Perhaps you should read it?\n");
}

status auto_load() {
  return((int)environment()->query_level() < 5) ? 1 : 0;
}

void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if((int)this_player()->query_level() > 4) {
    write("The scroll is blown away by the wind. . . \n");
    destruct(this_object());
    return 1;
  }
  if(id(str)) {
    this_player()->more("/open/newbie.txt");
    return 1;
  }
}
