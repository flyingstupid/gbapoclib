#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("aggressively");
  set_origin_view("You $[tackle $t|wrestle with yourself on the ground$] $a.");
  set_target_view("$e tackles you $a.");
  set_other_view("$e $[tackles $t|wrestles with $oself on the ground$] $a.");
}
