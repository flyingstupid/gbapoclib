#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("in Italian");
  set_origin_view("You sing $a.");
  set_other_view("$e sings $a.");
}
