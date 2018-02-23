#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("sheepishly");
  set_origin_view("You cower $a$[ in $t's presence$].");
  set_target_view("$e cowers $a in your presence.");
  set_other_view("$e cowers $a$[ in $t's presence$].");
}
