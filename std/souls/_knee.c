#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("painfully");
  set_origin_view("You $[knee $t|look around to knee someone$] $a.");
  set_target_view("$e knees you $a.");
  set_other_view("$e $[knees $t|looks around to knee somone$] $a.");
}
