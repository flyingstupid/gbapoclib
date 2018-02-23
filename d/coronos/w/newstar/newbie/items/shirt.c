#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("heavy shirt");
  set_alias("shirt");
  set_short("a heavy shirt");
  set_long(
    "This is a tattered shirt made from many differnt kinds of fabric.\n"+
    "It is very thick, providing protection to its wearer.  Dirt and \n"+
    "filth cake the shirt both inside and out.\n");
  set_type("armour");
  set_armour_material("cloth");
  set_ac(1);
  set_weight(3);
  set_value(130);
  set_sell_destruct(1);
}
 
