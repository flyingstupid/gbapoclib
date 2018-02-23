/* BANDMAIL.C
   AUTHOR:NIGHTBRINGER
   04-24-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("banded mail");
  set_type("armour");
  set_short("a finely crafted suit of banded mail armour");
  set_long("A very nicely made suit of bandedmail armour\n");
  set_ac(4);
  set_weight(3);
  set_value(5600);
  set_info("This will protect you pretty good.\n");
  set_armour_material("steel");
}
