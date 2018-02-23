/* BLACK ROBE
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("black robe");
  set_type("cloak");
  set_short("a plain black cloak");
  set_long("This is a nice black robe, with runes inscribed upon it.\n");
  set_ac(1);
  set_weight(1);
  set_value(300);
  set_info("A robe of protection.\n");
  set_armour_material("cloth");
}
