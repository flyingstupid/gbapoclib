#include <mudlib.h>
#define NAME	(string)this_player()->query_name()

inherit CONTAINER;

void reset(status arg) {
  if(arg) return;
  set_name("quiver");
  set_short("A quiver");
  set_long("A fine quiver made from leather and soft furs. This long \n"+
           "container is designed primarily to keep arrows and bolts \n"+
           "from breaking.\n");
  set_max_weight(10);
  set_weight(1);
  set_value(1000);
}

void init() {
  ::init();
  add_action("load_me", "load");
}

status load_me(string str) {
  int i;
  object *inv;
  status havePut;

  inv = all_inventory(environment());

  if(str == "quiver") {
    for(i=0; i<sizeof(inv); i++) {
      if(!inv[i]->id("arrow")) {
        continue;
      }
      if(!add_weight(inv[i]->query_weight())) {
        write(inv[i]->short()+" won't fit inside the "+query_name()+".\n");
        continue;
      }
      move_object(inv[i], this_object());
      havePut = 1;
      write("You put the arrow in the quiver.\n");
      say(NAME+" puts an arrow in a quiver.\n");
    }
  }
  if(!havePut) {
    notify_fail("You don't have any arrows to put into the quiver.\n");
    return 0;
  }
  return 1;
}

