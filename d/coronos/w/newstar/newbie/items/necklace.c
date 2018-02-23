#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("necklace");
  set_alias("amulet");
  set_short("a necklace");
  set_long(
    "This is a simple necklace made from a silver chain and a small\n"+
    "amulet.  The amulet has a tiny preciousstone in it.  The stone\n"+
    "looks to be an opal.  The necklace is very old.\n");
  set_type("amulet");
  set_ac(1);
  set_weight(1);
  set_sell_destruct(1);
  set_value(300);
}
