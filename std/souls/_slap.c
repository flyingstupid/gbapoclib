#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("sharply");
  set_origin_view("You slap $[$t|yourself$] $a.");
  set_target_view("$e slaps you $a.");
  set_other_view("$e slaps $[$t|$oself$] $a.");
}
