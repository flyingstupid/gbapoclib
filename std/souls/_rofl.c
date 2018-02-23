#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("hysterically");
  set_origin_view("You roll around on the floor laughing $a$[ at $t$]!");
  set_target_view("$e rolls around on the floor laughing $a at you!");
  set_other_view("$e rolls around on the floor laughing $a$[ at $t$]!");
}
