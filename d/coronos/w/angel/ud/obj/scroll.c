#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
  if(arg) return;

  set_short("a scroll");
  set_long(
	"A scroll. Perhaps you should read it?\n");
  set_weight(1);
  set_value(10);
  set_name("scroll");
  set_alias("lifestealer scroll");
}

void init() {
  ::init();
  add_action("read_me", "read");
}

status read_me(string str) {
  if(id(str)) {
    write(
    "Dear Curzon\n"+
    "This messenger I send to you has the deadly weapon we have sought to \n"+
    "destroy. I ask that you give this person the whereabouts of the place\n"+
    "we discussed that could destroy it.\n\n"+
    "I leave this in your capable hands.\n"+
    "Lord Alastaire Nighthawk, regent of Ille Coronos.\n");
    return 1;
  }
  return 0;
}

