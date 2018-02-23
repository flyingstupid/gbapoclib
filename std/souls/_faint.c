#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("dead away");
  set_origin_view("You faint $a.");
  set_other_view("$e faints $a.");
}
