#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("helplessly");
  set_origin_view("You shrug $a.");
  set_other_view("$e shrugs $a.");
}
