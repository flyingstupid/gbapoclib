#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("knowingly");
  set_origin_view("You snap your fingers $a.");
  set_other_view("$e snaps $p fingers $a.");
}
