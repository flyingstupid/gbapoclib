/* RING OF PROTECTION, +2
   AUTHOR: NIGHTBRINGER
   06-02-97 */

#include <mudlib.h>
inherit MAGIC_ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("ring");
  set_type("ring");
  set_short("Silver Ring");
  set_long("A marvelously crafted silver ring.\n");
  set_info("This ring protects the wearer from almost anything.\nAc: 2\nWeight: 1\n");
  set_ac(2);
  set_weight(1);
  set_value(900);
  set_armour_material("silver");
}
