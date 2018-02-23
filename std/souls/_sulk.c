#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("in the corner");
  set_adverb_required(1);
  set_origin_view("You sulk $a.");
  set_other_view("$e sulks $a.");
}
