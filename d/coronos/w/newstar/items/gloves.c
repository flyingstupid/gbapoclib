/*Newstar*/
#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("riding gloves");
  set_alias("gloves");
  set_short("riding gloves");
  set_long(
    "This is a pair of leather riding gloves that would be worn by\n"+
    "someone with good horsemanship.  They are made of black leather,\n"+
    "the backs studded with silver.  They provide the prefect protection\n"+
    "against chafing, while in the saddle, but can also be worn just so.\n");
  set_type("gloves");
  set_armour_material("leather");
  set_ac(1);
  set_weight(2);
  set_plural("riding gloves");
  set_value(250);
  set_sell_destruct(1);
}
