#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("softly");
  set_origin_view("You nuzzle $[$t's cheek|a nearby tree$] $a.");
  set_target_view("$e nuzzles your cheek $a.");
  set_other_view("$e nuzzles $[$t's cheek|a nearby tree$] $a.");
}
