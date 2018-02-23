#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("sarcastically");
  set_origin_view("You roll your eyes $[at $t $]$a.");
  set_target_view("$e rolls $p eyes at you $a.");
  set_other_view("$e rolls $p eyes $[at $t $]$a.");
}
