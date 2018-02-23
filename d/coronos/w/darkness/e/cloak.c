#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("light cloak");
  set_alias("cloak");
  set_short("a light cloak");
  set_plural("light cloaks");
  set_long(
    "This is a simple cloak of elven make.  It is a deep brown color, with\n"+
    "hints of dark green.  The light material that the cloak is made from\n"+
    "is very sturdy and strong. The bottom of the cloak is cut short, just\n"+
    "below the hips to allow the legs more freedom when running.  A hood\n"+
    "and leather fasteners adorn the collar area of this cloak.\n");
  set_type("cloak");
  set_armour_material("cloth");
  set_ac(1);
  set_weight(1);
  set_value(300);
  set_sell_destruct(1);
}
