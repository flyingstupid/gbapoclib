#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("proudly");
  set_origin_view("You strut $a.");
  set_other_view("$e struts $a.");
}
