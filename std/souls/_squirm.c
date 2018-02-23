#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("helplessly");
  set_origin_view("You squirm $a$[ to get away from $t$].");
  set_target_view("$e squirms $a to get away from you.");
  set_other_view("$e squirms $a$[ to get away from $t$].");
}
