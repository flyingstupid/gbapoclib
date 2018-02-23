/* CLOAK.C
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_type("cloak");
  set_short("a plain black cloak");
  set_long("This is a ordinary cloak, made of heavy wool.\n");
  set_ac(1);
  set_weight(2);
  set_value(600);
  set_info("It wont offer you much protection, but it'll keep you warm.\n");
  set_armour_material("cloth");
}
