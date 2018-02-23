#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("egotistically");
  set_origin_view("You flex your bulging muscles $[at $t $]$a.");
  set_target_view("$e flexes $p bulging muscles at you $a.");
  set_other_view("$e flexes $p bulging muscles $[at $t $]$a.");
}
