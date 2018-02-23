/* HERCHAIN.C
   AUTHOR:NIGHTBRINGER
   04-24-97 */

#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("chain mail");
  set_type("armour");
set_short("a suit if chainmail armour");
  set_long("A very nicely made suit af chainmail, it bears the crest of \n"+
           "the D'ghoe family.\n");
  set_ac(3);
  set_weight(2);
  set_value(2500);
  set_info("This will protect you pretty good.\n");
  set_armour_material("steel");
}

