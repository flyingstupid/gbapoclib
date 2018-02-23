#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("excitedly");
  set_origin_view("You bounce around $a.");
  set_other_view("$e bounces around $a.");
}
