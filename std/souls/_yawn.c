#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("tiredly");
  set_origin_view("You yawn $a.");
  set_other_view("$e yawns $a.");
}
