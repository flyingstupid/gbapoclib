#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("strangely");
  set_origin_view("You look $[at $t |around $]$a and go 'EH!?'");
  set_target_view("$e looks at you $a and goes 'EH!?'");
  set_other_view("$e looks $[at $t |around $]$a and goes 'EH!?'");
}
