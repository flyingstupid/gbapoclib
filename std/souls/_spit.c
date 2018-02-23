#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("in disgust");
  set_origin_view("You spit on $[$t|the ground$] $a.");
  set_target_view("$e spits on you $a.");
  set_other_view("$e spits on $[$t|the ground$] $a.");
}
