#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("quizzically");
  if(arg) return;
  set_origin_view("You arch an eyebrow $a$[ at $t$].");
  set_target_view("$e arches an eyebrow $a at you.");
  set_other_view("$e arches an eyebrow $a$[ at $t$].");
}
