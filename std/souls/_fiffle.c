#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("delightedly");
  set_origin_view("You fiffle $a.");
  set_other_view("$e fiffles $a.");
}
