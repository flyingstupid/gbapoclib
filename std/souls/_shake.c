#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("warmly");
  set_origin_view("You shake $[$t's hand $a|your head$].");
  set_target_view("$e shakes your hand $a.");
  set_other_view("$e shakes $[$t's hand $a|$p head$].");
}
