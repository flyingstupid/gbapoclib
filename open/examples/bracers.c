#include <mudlib.h>
inherit ARMOUR;

void reset(status arg) {
  if(arg) return;
  set_name("bracers");
  set_type("armour");
  set_short("A pair of golden arm bands");
  set_alias("bands");
  set_alt_name("arm bands");
  set_ac(3); /* bracers +3 */
  set_weight(2);
  set_value(2500);
  set_plural("pairs of bracers");
  set_info("These arm brands are bracers of defence, granting the \n"+
           "wearer magical protection, equal to armour, without "+
           "the bulk.\n");
}

