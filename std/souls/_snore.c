#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("peacefully");
  set_origin_view("You snore $a.");
  set_other_view("$e snores $a.");
}
