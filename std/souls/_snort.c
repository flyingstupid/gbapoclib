#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("angrily");
  set_origin_view("You snort $[at $t $]$a.");
  set_target_view("$e snorts at you $a.");
  set_other_view("$e snorts $[at $t $]$a.");
}
