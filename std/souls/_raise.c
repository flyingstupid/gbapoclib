#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("quizzically");
  set_origin_view("You raise an eyebrow $a$[ at $t$].");
  set_target_view("$e raises an eyebrow $a at you.");
  set_other_view("$e raises an eyebrow $a$[ at $t$].");
}
