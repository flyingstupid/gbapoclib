/* lantern.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit "objects/torch";

int query_value() { return 4; }  

void reset(status arg) {
  if(arg) return;

  set_name("lantern");
  set_short("a lantern");
  set_plural("lanterns");
  set_long(
    "This is a simple lantern with a little oil in it.  The glass\n"+
    "panels are somewhat cloudy and the metal is rusted.\n");
  set_extra_info("Looking at the lantern, you think it "+
                 "will last for another @@query_approx_time:"+
                 file_name(this_object()) +"@@.\n");

  set_smell("The lantern oil smells very musty.\n");

  set_weight(1);
  set_max_fuel(1000);
  fuel = 200;
  light_intensity = 1;
}
