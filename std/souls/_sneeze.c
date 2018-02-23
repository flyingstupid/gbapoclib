#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("violently");
  set_origin_view("You sneeze $a.");
  set_other_view("$e sneezes $a.");
}
