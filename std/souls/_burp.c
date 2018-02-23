#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("rudely");
  set_origin_view("You burp $a.");
  set_other_view("$e burps $a.");
}
