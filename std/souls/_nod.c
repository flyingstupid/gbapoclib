#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("understandingly");
  set_origin_view("You nod $a$[ at $t$].");
  set_target_view("$e nods $a at you.");
  set_other_view("$e nods $a$[ at $t$].");
}
