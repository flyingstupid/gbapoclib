#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("enthusiastically");
  set_origin_view("You cheer $[for $t $]$a.");
  set_target_view("$e cheers for you $a.");
  set_other_view("$e cheers $[for $t $]$a.");
}
