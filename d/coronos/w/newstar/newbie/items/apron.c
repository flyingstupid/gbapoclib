#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("cloth apron");
  set_alias("apron");
  set_short("an apron");
  set_long(
    "This is a frilly, blue apron usually worn when cooking in the kitchen.\n"+
    "It has a pattern of little white and pink flowers on a blue background.\n"+
    "Lace and ruffles border this cute apron.\n");
  set_type("cloak");
  set_armour_material("cloth");
  set_ac(1);
  set_weight(2);
  set_value(200);
  set_sell_destruct(1);
}

