#include <mudlib.h>
inherit ARMOUR;

void reset(status arg) {
  if(arg) return;
  set_short("a shield");
  set_name("shield");
  set_type("shield");
  set_ac(2);
  set_weight(2);
  set_value(1000);
  set_long("A nice metal shield.\n");
}
