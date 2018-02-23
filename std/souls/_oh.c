#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You look blank and say 'oh'.");
  set_other_view("$e looks blank and says 'oh'.");
}
