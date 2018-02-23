#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("delightedly");
  set_adverb_required(1);
  set_origin_view("You giggle $a $[at $t$].");
  set_target_view("$e giggles $a at you.");
  set_other_view("$e giggles $a $[at $t$].");
}
