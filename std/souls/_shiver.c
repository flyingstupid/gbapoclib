#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("from the cold");
  set_origin_view("You shiver $a.");
  set_other_view("$e shivers $a.");
}
