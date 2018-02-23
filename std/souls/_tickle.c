#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("mercilessly");
  set_adverb_required(1);
  set_origin_view("You tickle $[$t|yourself$] $a.");
  set_target_view("$e tickles you $a.");
  set_other_view("$e tickles $[$t|$oself$] $a.");
}
