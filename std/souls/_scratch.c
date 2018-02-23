#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_origin_view("You scratch your head and say 'umm'.");
  set_other_view("$e scratches $p head and says 'umm'.");
}
