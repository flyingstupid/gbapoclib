#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("uncontrollably");
  set_origin_view("You hiccup $a.");
  set_other_view("$e hiccups $a.");
}
