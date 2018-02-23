#include <mudlib.h>
inherit ARMOUR;

void reset(status arg) {
  if(arg) return;
  set_name("leather");
  set_type("armour");
  set_armour_material("leather");
  set_short("A suit of leather armour");

  set_long(
"This suit of leather armour is made from the finest of hides \n"+
"and is designed in the fashion of the Black Guard of Ille    \n"+
"Coronos. There is a golden circle above the left breast and  \n"+
"a golden officers stripe on the left lapel.\n");

  set_ac(2);     /* +1 leather armour */
  set_weight(2);
  set_value(600);
  set_enchanted(1);
}
