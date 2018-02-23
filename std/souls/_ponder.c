#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("thoughtfully");
  set_origin_view("You ponder the situation $a.");
  set_other_view("$e ponders the situation $a.");
}
