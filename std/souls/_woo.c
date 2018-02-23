#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You go Woo Hoo$[ at $t$]!");
  set_target_view("$e goes Woo Hoo at you!");
  set_other_view("$e goes Woo Hoo$[ at $t$]!");
}
