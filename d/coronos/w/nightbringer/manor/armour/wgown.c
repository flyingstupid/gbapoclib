/* WHITE GOWN
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("white gown");
  set_type("cloak");
  set_short("a white gown");
  set_long("This is a nice white gown, with runes inscribed upon it.\n");
  set_ac(1);
  set_weight(1);
  set_value(300);
  set_info("A gown of protection.\n");
  set_armour_material("cloth");
}
