#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("cautiously");
  set_origin_view("You prod at $[$t|the air$] $a.");
  set_target_view("$e prods at you $a.");
  set_other_view("$e prods at $[$t|the air$] $a.");
}
