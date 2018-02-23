#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("softly");
  set_origin_view("You chortle $a.");
  set_other_view("$e chortles $a.");
}
