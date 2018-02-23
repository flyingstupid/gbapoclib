#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("gleefully");
  set_adverb_required(1);
  set_origin_view("You cackle $a.");
  set_other_view("$e throws $p head back and cackles $a.");
}
