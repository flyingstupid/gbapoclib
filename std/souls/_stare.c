#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("curiously");
  set_origin_view("You stare $[at $t $a|into space$].");
  set_target_view("$e stares at you $a.");
  set_other_view("$e stares $[at $t $a|into space$].");
}
