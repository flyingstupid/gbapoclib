#include <mudlib.h>
inherit "objects/torch";

void reset(status arg) {
  if(arg) return;

  set_name("lamp");
  set_short("an ornamental glass lamp");
  set_long(
    "This is a delicate oil lamp made from clear glass.  The stout cylinder \n"+
    "of glass has a flat bottom and a rounded top.  There is a small, glass \n"+
    "stopper at the top of the lamp in which the wick is pulled through.    \n"+
    "Towards the bottom of the lamp is a handle, much like that of a tea cup.\n"+
    "Intricate designs border the top and bottom of the lamp, adding to its \n"+
    "simple beauty. Clear lamp oil is used to fuel lamps such as this one. \n");
  set_extra_info("Looking at the steady flame, you think the lamp\n"+
                 "will last for another @@query_approx_time:"+
                 file_name(this_object()) +"@@.\n");

  set_value(1000);
  set_weight(2);
  set_max_fuel(6000);
  fuel = 6000;
  light_intensity = 2;
}
