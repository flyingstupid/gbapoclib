#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("slowly");
  set_origin_view("You fall to the ground and $a die!");
  set_other_view("$e falls to the ground and $a dies!");
}
