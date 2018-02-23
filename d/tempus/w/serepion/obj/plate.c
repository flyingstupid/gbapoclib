#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("platemail");
  set_type("armour");
  set_short("Oriental platemail");
  set_long("A beautiful suit of ceramic platemail decorated with a golden\n"+
     "dragon on the front. Oriental style pictures cover it.\n");
  set_ac(4);
  set_value(4250);
  set_armour_material("ceramic");
}
