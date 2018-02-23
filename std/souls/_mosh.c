#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("madly");
  set_origin_view("You mosh $[into $t|around the room$] $a.");
  set_target_view("$e moshes into you $a.");
  set_other_view("$e moshes $[into $t|around the room$] $a.");
}
