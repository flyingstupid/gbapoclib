/* a bag */

#include <mudlib.h>
inherit CONTAINER;

void reset(status arg) {
  if(arg) return;
  set_name("sack");
  set_plural("sacks");
  set_alias("bag");
  set_short("A small sack");
  set_long("A small sack which once held grain.\n");
  set_max_weight(10);
  set_value(12);
  set_weight(1);
}
