#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("politely");
  set_adverb_required(1);
  set_origin_view("You chuckle $a $[at $t$].");
  set_target_view("$e chuckles $a at you.");
  set_other_view("$e chuckles $a $[at $t$].");
}
