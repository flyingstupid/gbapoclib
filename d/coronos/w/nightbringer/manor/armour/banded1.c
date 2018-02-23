/* BANDMAIL +1
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("banded mail");
  set_type("armour");
set_short("a suit of banded mail armour");
  set_long("A very nicely made suit of bandedmail armour\n");
  set_ac(5);
  set_weight(4);
  set_value(9000);
  set_info("This will deffinately do the job.\n");
  set_armour_material("steel");
  set_enchanted(1);
}
