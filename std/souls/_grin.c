#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("widely");
  set_adverb_required(1);
  set_origin_view("You grin $a$[ at $t$].");
  set_target_view("$e grins $a at you.");
  set_other_view("$e grins $a$[ at $t$].");
}
