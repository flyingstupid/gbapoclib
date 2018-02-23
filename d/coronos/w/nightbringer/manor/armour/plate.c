/* PLATE MAIL
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("platemail");
  set_type("armour");
  set_short("a finely crafted suit of plate mail armour");
  set_long("A very nicely made suit of plate mail armour\n");
  set_ac(4);
  set_weight(3);
  set_value(5600);
  set_info("This will protect you really good.\n");
  set_armour_material("steel");
}
