#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("painfully");
  set_origin_view("You wince $a$[ before $t$].");
  set_target_view("$e winces $a before you.");
  set_other_view("$e winces $a$[ before $t$].");
}
