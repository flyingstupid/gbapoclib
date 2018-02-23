#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
  set_weight(2);
  set_value(100);
  set_short("a bell");
  set_long("A fine bell, made from brass.\n");
}

void init() {
  ::init();
  add_action("ring_me", "ring");
}

status ring_me() {
  write("You ring the bell loudly!\n");
  say(this_player()->query_name()+" rings "+
	environment()->query_possessive()+" bell LOUDLY!\n");
  return 1;
}
