#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("loudly");
  set_origin_view("You groan $a.");
  set_other_view("$e groans $a.");
}
