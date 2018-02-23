#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view(
    "$[You sweep $t across the dance floor.|Feels silly, doesn't it?$]");
  set_target_view("$e sweeps you across the dance floor.");
  set_other_view("$e $[sweeps $t across the dance floor|does the disco duck$].");
}
