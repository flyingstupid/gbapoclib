#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("quickly");
  set_origin_view("You $a duck$[ away from $t$].");
  set_target_view("$e $a ducks away from you.");
  set_other_view("$e $a ducks$[ away from $t$].");
}
