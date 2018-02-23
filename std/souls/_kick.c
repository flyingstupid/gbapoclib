#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("mischievously");
  set_adverb_required(1);
  set_origin_view("You kick $[$t|yourself$] $a.");
  set_target_view("$e kicks you $a.");
  set_other_view("$e kicks $[$t|$oself$] $a.");
}
