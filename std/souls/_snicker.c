#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("cheekily");
  set_origin_view("You snicker $a.");
  set_other_view("$e snickers $a.");
}
