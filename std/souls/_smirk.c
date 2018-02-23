#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("in amusement");
  set_adverb_required(1);
  set_origin_view("You smirk $a.");
  set_other_view("$e smirks $a.");
}
