#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("playfully");
  set_origin_view("You pinch $[$t $a|yourself sharply$].");
  set_target_view("$e pinches you $a.");
  set_other_view("$e pinches $[$t $a|$oself sharply$].");
}
