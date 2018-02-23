#include <mudlib.h>
inherit CONTAINER;

void reset(status arg) {
  if(arg) return;
  set_name("bag");
  set_short("An old bag");
  set_long("A very small bag barely holding itself together.\n");
  set_max_weight(5);
  set_container_weight(1);
  set_value(4);
  set_weight(1);
}
