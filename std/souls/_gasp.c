#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("in astonishment");
  set_origin_view("You gasp $a.");
  set_other_view("$e gasps $a.");
}
