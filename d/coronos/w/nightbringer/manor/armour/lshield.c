/* LARGE SHIELD
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("large shield");
set_type("shield");
  set_short("A very nice shield");
  set_long("A large shield that is triangular in shape with rounded\n"+
  "edges. It bears the Rochester family crest of two Serpants entertwined\n");
  set_ac(2);
  set_weight(1);
  set_value(900);
  set_info("This will protect you pretty good.\n");
  set_armour_material("steel");
}
