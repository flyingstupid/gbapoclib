#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("dangerously");
  set_origin_view("You growl $a$[ at $t$].");
  set_target_view("$e growls $a at you.");
  set_other_view("$e growls $a$[ at $t$].");
}
