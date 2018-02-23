#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("sarcastically");
  set_origin_view("You wiggle your bottom $a.");
  set_other_view("$e wiggles $p bottom $a.");
}
