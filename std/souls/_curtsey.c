#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("gracefully");
  set_origin_view("You curtsey $a$[ to $t$].");
  set_target_view("$e curtseys $a to you.");
  set_other_view("$e curtseys $a$[ to $t$].");
}
