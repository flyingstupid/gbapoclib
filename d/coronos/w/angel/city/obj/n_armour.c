#include <mudlib.h>

inherit ARMOUR;

void reset(status arg) {
  if(arg) return;
  set_type("armour");
  set_name("leather armour");
  set_armour_material("leather");

  set_short("a suit of leather armour");
  set_long(
"This suit of leather armour looks well looked after, \n"+
"and bears a small seal of an eagle, one side black,  \n"+
"and the other side red.\n");

  set_ac(1);
  set_weight(2);
  set_value(1);          /* not much so dont get money */
  set_sell_destruct(1);
}
