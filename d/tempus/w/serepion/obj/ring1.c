#include <mudlib.h>
inherit MAGIC_ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("ring");
  set_type("ring");
  set_short("Utterly black ring");
  set_long("A marvelously crafted black ring made of a strange metal.\n");
  set_info("This ring protects the wearer from almost anything");
  set_ac(0);
  set_weight(1);
  set_value(1500);
  set_armour_material("adamantite");
  set_protection("fire");
  set_protection("cold");
  set_protection("lightning");
  set_protection("air");
  set_protection("water");
  set_protection("earth");
  set_protection("draining");
  set_protection("death");
  set_protection("darkness");
  set_protection("light");
  set_protection("acid");
  set_protection("poison");
  set_protection("disease");
  set_protection("fear");
  set_protection("charm");
}
