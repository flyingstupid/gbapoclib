#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("suggestively");
  set_origin_view("You wink $a$[ at $t$].");
  set_target_view("$e winks $a at you.");
  set_other_view("$e winks $a$[ at $t$].");
}
