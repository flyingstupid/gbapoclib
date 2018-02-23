#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("obnoxiously");
  set_origin_view("You fart $a.");
  set_other_view("$e farts $a.");
}
