#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("warmly");
  set_origin_view("You kiss $[$t's hand|your hand$] $a.");
  set_target_view("$e kisses your hand $a.");
  set_other_view("$e kisses $[$t's hand|$p hand$] $a.");
}
