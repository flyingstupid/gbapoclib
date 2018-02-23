#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("deeply");
  set_origin_view("You sigh $a.");
  set_other_view("$e sighs $a.");
}
