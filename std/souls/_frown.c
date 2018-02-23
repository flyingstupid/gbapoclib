#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("impatiently");
  set_origin_view("You frown $a.");
  set_other_view("$e frowns $a.");
}
