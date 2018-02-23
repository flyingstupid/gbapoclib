#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("head over heals");
  set_origin_view("You flip $a.");
  set_other_view("$e flips $a.");
}
