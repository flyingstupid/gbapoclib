#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("tattered boots");
  set_alias("boots");
  set_short("tattered boots");
  set_long(
    "This is a set of tattered, cloth boots.  The are very simple foot\n"+
    "coverings made from heavy cloth, and bound with leather straps.\n"+
    "They do provide some protection to their wearer.\n");
  set_type("boots");
  set_armour_material("cloth");
  set_ac(1);
  set_weight(2);
  set_value(200);
  set_sell_destruct(1);
}
 
