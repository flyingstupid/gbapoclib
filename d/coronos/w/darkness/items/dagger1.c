#include <mudlib.h>

inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("dagger");
  set_short("a dagger");
  set_long(
    "This is a small dagger made from a lightweight metal.\n");
  set_length(9);
  set_type("slash");
  set_value(150);
  set_wc(8);
  set_weight(1);
}
 

