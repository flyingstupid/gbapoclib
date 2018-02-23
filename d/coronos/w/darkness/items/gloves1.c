#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("gloves");
  set_alias("leather");
  set_short("leather gloves");
  set_long("This is a pair of black leather gloves.  They look\n"+
    "to be very comfortable and protective.\n");
  set_type("gloves");
  set_armour_material("leather");
  set_ac(1);
  set_weight(1);
  set_value(250);
}
