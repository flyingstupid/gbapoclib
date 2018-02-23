#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("sharply");
  set_origin_view("You salute $[$t $]$a.");
  set_target_view("$e salutes you $a.");
  set_other_view("$e salutes $[$t $]$a.");
}
