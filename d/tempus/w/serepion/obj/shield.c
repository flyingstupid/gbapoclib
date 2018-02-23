#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("shield");
  set_type("shield");
  set_short("Oriental shield");
  set_long("Beautifully decorated ceramic shield in oriental styling.\n");
  set_ac(2);
  set_weight(2);
  set_value(650);
  set_armour_material("ceramic");
}
