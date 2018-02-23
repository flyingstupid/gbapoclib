#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("painfully");
  set_origin_view("You lag $a.");
  set_other_view("$e lags $a.");
}
