#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("rudely");
  set_origin_view("You $a stick your tongue out$[ at $t$].");
  set_target_view("$e $a sticks $p tongue out at you.");
  set_other_view("$e $a sticks $p tongue out$[ at $t$].");
}
