#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("loudly");
  set_origin_view("You laugh $a $[at $t$].");
  set_target_view("$e laughs $a at you.");
  set_other_view("$e laughs $a $[at $t$].");
}
