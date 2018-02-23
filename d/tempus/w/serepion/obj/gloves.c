#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("gloves");
  set_type("gloves");
  set_short("Oriental gloves");
  set_long("Beautifully decorated ceramic boots in oriental styling.\n");
  set_ac(1);
  set_weight(2);
  set_value(225);
  set_armour_material("ceramic");
}
