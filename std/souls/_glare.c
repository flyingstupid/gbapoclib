#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("seriously");
  set_origin_view("You glare $[at $t $]$a.");
  set_target_view("$e glares at you $a.");
  set_other_view("$e glares $[at $t $]$a.");
}
