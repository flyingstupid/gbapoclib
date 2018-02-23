#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("embarrassedly");
  if(arg) return;
  set_origin_view("You blush $a.");
  set_other_view("$e blushes $a.");
}
