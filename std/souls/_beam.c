#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("brightly");
  if(arg) return;
  set_adverb_required(1);
  set_origin_view("You beams $a$[ at $t$].");
  set_target_view("$e beams $a at you.");
  set_other_view("$e beams $a$[ at $t$].");
}
