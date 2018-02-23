#include <mudlib.h>
inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("smartly");
  set_origin_view("You offer your hand $[to $t $]$a.");
  set_target_view("$e offers $p hand to you $a.");
  set_other_view("$e offers $p hand $[to $t $]$a.");
}
