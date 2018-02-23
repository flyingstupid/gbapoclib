#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("accusingly");
  set_origin_view("You $[point at $t $a|try foolishly to point in all "+
    "directions at once$].");
  set_target_view("$e points at you $a.");
  set_other_view("$e $[points at $t $a|tries foolishly to point in all "+
    "directions at once$].");
}
