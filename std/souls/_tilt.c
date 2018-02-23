#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("curiously");
  set_origin_view("You tilt your head to the side and look $[at $t|around$]"+
    " $a.");
  set_target_view("$e tilts $p head to the side and looks at you $a.");
  set_other_view("$e tilts $p head to the side and looks $[at $t|around$]"+
    " $a.");
}
