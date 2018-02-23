#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_type("cloak");
  set_short("Fine black cloak");
  set_long("This is one of the finest cloaks you've ever seen, made of fabulous cloth.\n");
  set_ac(2);
  set_weight(2);
  set_value(700);
  set_armour_material("cloth");
  set_sell_destruct(1);
}
