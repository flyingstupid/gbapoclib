#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("scornfully");
  set_origin_view("You sneer $[at $t $]$a.");
  set_target_view("$e sneers at you $a.");
  set_other_view("$e sneers $[at $t $]$a.");
}
