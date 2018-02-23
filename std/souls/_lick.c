#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("profusely");
  set_origin_view("You lick $[$t|yourself$] $a.");
  set_target_view("$e licks you $a.");
  set_other_view("$e licks $[$t|$oself$] $a.");
}
