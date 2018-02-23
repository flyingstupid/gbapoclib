#include <mudlib.h>
inherit FOOD;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mushroom");
  set_short("a mushroom");
  set_long("A small brown and white mushroom.\n");
  set_value(1);
  set_sell_destruct(1);
  set_strength(0);
  set_weight(1);
}
