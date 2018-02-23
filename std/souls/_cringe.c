#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("in terror");
  set_origin_view("You cringe $[before $t $]$a.");
  set_target_view("$e cringes before you $a.");
  set_other_view("$e cringes $[before $t $]$a.");
}
