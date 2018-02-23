#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("helmet");
  set_type("helmet");
  set_short("Oriental helmet");
  set_long("Beautifully decorated ceramic helmet in oriental styling.\n");
  set_ac(1);
  set_weight(2);
  set_value(225);
  set_armour_material("ceramic");
}
