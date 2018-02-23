#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("softly");
  set_origin_view("You nudge $[$t|yourself$] $a.");
  set_target_view("$e nudges you $a.");
  set_other_view("$e nudges $[$t|$oself$] $a.");
}
