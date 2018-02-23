#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("spontaneously");
  set_origin_view("You pounce on $[$t|a nearby rock$] $a.");
  set_target_view("$e pounces on you $a.");
  set_other_view("$e pounces on $[$t|a nearby rock$] $a.");
}
