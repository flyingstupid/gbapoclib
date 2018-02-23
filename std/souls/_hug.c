#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("warmly");
  set_origin_view("You $[hug $t $a.|need a hug!$]");
  set_target_view("$e hugs you $a.");
  set_other_view("$e $[hugs $t $a.|needs a hug!$]");
}
