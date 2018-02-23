#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("impatiently");
  set_origin_view("You tap your foot $a$[ at $t$].");
  set_target_view("$e taps $p foot $a at you.");
  set_other_view("$e taps $p foot $a$[ at $t$].");
}
