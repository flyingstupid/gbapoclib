#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("leather armour");
  set_alias("armor");
  set_short("leather armor");
  set_plural("sets of leather armour");
  set_long(
    "This leather armour is of elvish make.  Strong pieces of leather\n"+
    "have been fastened tightly with cord to make a very light and\n"+
    "strong piece of protective gear.\n"); 
  set_type("armour");
  set_armour_material("leather");
  set_ac(1);
  set_weight(1);
  set_value(300);
  set_sell_destruct(1);
}
