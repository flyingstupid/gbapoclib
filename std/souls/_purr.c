#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("contentedly");
  set_origin_view("You purr $a.");
  set_other_view("$e purrs $a.");
}
