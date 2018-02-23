#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("grumpily");
  set_origin_view("You moan $a.");
  set_other_view("$e moans $a.");
}
