#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You blink $a.");
  set_other_view("$e blinks $a.");
}
