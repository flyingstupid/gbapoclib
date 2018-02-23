#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("wholeheartedly");
  if(arg) return;
  set_origin_view("You agree $[with $t $]$a.");
  set_target_view("$e agrees with you $a.");
  set_other_view("$e agrees $[with $t $]$a.");
}
