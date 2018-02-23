#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("fondly");
  set_origin_view("You kiss $[$t $a|the air in front of you$].");
  set_target_view("$e kisses you $a.");
  set_other_view("$e kisses $[$t $a|the air in front of $o$].");
}
