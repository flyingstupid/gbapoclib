#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("intently");
  set_origin_view("You listen$[ to $t$] $a.");
  set_target_view("$e listens to you $a.");
  set_other_view("$e listens$[ to $t$] $a.");
}
