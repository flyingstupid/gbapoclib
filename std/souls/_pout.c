#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("sadly");
  set_origin_view("You pout $a.");
  set_other_view("$e pouts $a.");
}
