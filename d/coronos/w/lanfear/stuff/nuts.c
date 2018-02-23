#include <mudlib.h>
inherit FOOD;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("nuts");
  set_short("some nuts");
  set_long("A handful of tasty hazel-nuts.\n");
  set_value(5);
  set_sell_destruct(1);
  set_strength(2);
  set_weight(1);
}

